/**
 *    Frame class extends FabricImage to represent a frame in the canvas
 *
 *    @param kind - The kind of frame: 'regular', 'shadow', or 'background'
 *    @param element - The HTML element to use as the source of the frame (usually a canvas)
 *    @param options - Additional options for the frame. See FabricImage for available options.
 *    @returns {Object} - An object representation of the frame
 */
class Frame extends fabric.FabricImage {
  static type = "frame";

  constructor(element, options = {}) {
    super(element, options);
    this.kind = options.kind ?? "regular"; // or 'shadow' or 'background'
  }
}

fabric.classRegistry.setClass(Frame);

/**
 *    Creates a new frame with the given properties. The stream is a
 *    Uint8ClampedArray of pixel data split between RGBA channels.
 *
 *    @param id - The ID of the frame
 *    @param pixels - The pixel data for the frame
 *    @param width - The width of the frame
 *    @param height - The height of the frame
 *    @param offsetX - The x offset of the frame
 *    @param offsetY - The y offset of the frame
 *    @returns {Object} - An object representation of the frame
 */
function makeFrame({ id, pixels, width, height, offsetX = 0, offsetY = 0 }) {
  const source = document.createElement("canvas");
  source.width = width;
  source.height = height;

  source
    .getContext("2d")
    .putImageData(
      new ImageData(new Uint8ClampedArray(pixels), width, height),
      0,
      0,
    );

  return { id, source, width, height, offsetX, offsetY };
}

/**
 *   LayerStack class manages the layers of frames in the canvas
 *
 *   @property {Array} background - Array of background frames (0 or 1)
 *   @property {Array} shadow - Array of shadow frames (ordered, animated)
 *   @property {Array} regular - Array of regular frames (ordered, animated)
 */
class LayerStack {
  constructor() {
    this.background = []; // 0 or 1 background frame
    this.shadow = []; // ordered frames (animated)
    this.regular = []; // ordered frames (animated)
  }

  /**
   *    Returns the array of frames for the given kind
   *
   *    @param kind - The kind of frame: 'regular', 'shadow', or 'background'
   *    @returns {Array} - The array of frames for the given kind
   */
  layer(kind) {
    return kind === "background"
      ? this.background
      : kind === "shadow"
        ? this.shadow
        : this.regular;
  }

  /**
   *    Reorders the frames of the given kind
   *
   *    @param kind - The kind of frame: 'regular', 'shadow', or 'background'
   *    @param from - The index of the frame to move
   *    @param to - The index where the frame should be moved
   */
  reorder(kind, from, to) {
    const layers = this.layer(kind);
    layers.splice(to, 0, layers.splice(from, 1)[0]);
  }

  /**
   *    Moves a frame from one layer to another
   *
   *    @param fromKind - The kind of the layer to move the frame from
   *    @param index - The index of the frame to move
   *    @param toKind - The kind of the layer to move the frame to
   */
  move(fromKind, index, toKind) {
    const frame = this.layer(fromKind).splice(index, 1)[0];
    if (toKind === "background") {
      this.regular.push(...this.background); // move existing bg to regular
      this.background = [frame];
    } else {
      this.layer(toKind).push(frame);
    }
  }
}

/**
 *   CanvasView class manages the Fabric.js canvas and its frames. Aka renders
 *   the frames to the canvas and handles user interactions.
 *
 *   @param fabricCanvas - The Fabric.js canvas instance
 */
class CanvasView {
  constructor(fabricCanvas) {
    this.canvas = fabricCanvas;

    const slot = (kind) => {
      const blank = document.createElement("canvas");
      blank.width = blank.height = 1;
      const f = new Frame(blank, {
        kind,
        imageSmoothing: false,
        selectable: true,
        objectCaching: false,
      });
      f.visible = false;
      return f;
    };

    this.slots = {
      background: slot("background"),
      shadow: slot("shadow"),
      regular: slot("regular"),
    };

    // insert order: z-order then bottom to top
    this.canvas.add(
      this.slots.background,
      this.slots.shadow,
      this.slots.regular,
    );
  }

  /**
   *   Renders the stack of frames on the canvas
   *
   *   @param stack - The stack of frames to render
   *   @param counter - The counter for animated frames to determine which frame to show
   */
  renderStack(stack, counter) {
    this._paint(this.slots.background, stack.background, 0); // static bg
    this._paint(this.slots.shadow, stack.shadow, counter); // animated shadow
    this._paint(this.slots.regular, stack.regular, counter); // animated regular
    this.canvas.requestRenderAll();
  }

  _paint(slot, frames, counter) {
    if (!frames.length) {
      slot.visible = false;
      return;
    }
    const frame = frames[counter % frames.length];
    if (slot._frameId !== frame.id) {
      slot.setElement(frame.source);
      // make sure slot visible and correct size
      slot.set({ width: frame.width, height: frame.height });
      slot._frameId = frame.id;
    }
    slot.set({ left: frame.offsetX, top: frame.offsetY, visible: true });
  }
}

window.editor = {
  canvas: null,
  view: null,
  stack: new LayerStack(),
  counter: 0,
  _timer: null,
  fps: 10,

  ensure(canvasId) {
    if (this.canvas) {
      return true;
    }

    if (typeof fabric === "undefined") {
      console.error("Fabric.js is not loaded.");
      return false;
    }

    const el = document.getElementById(canvasId);
    if (!el) {
      console.error(`Canvas element with id "${canvasId}" not found.`);
      return false;
    }

    return true;
  }
}