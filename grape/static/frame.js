import { FabricImage, classRegistry } from "fabric";

/**
 *    Frame class extends FabricImage to represent a frame in the canvas
 *
 *    @param kind - The kind of frame: 'regular', 'shadow', or 'background'
 *    @param order - The order of the frame indexed from 0
 *    @param layerId - The layer ID associated with the frame
 *    @returns {Object} - An object representation of the frame
 */
class Frame extends FabricImage {
  static type = "frame";

  constructor(element, options = {}) {
    super(element, options);
    this.kind = options.kind ?? "regular"; // or 'shadow' or 'background'
    this.order = options.order ?? 0;
    this.layerId = options.layerId ?? null;
  }

  toObject(props = []) {
    return {
      ...super.toObject([...props, "kind", "order", "layerId"]),
    };
  }
}

/**
 *    Creates a new cel with the given properties
 *
 *    @param id - The ID of the cel
 *    @param pixels - The pixel data for the cel
 *    @param width - The width of the cel
 *    @param height - The height of the cel
 *    @param offsetX - The x offset of the cel
 *    @param offsetY - The y offset of the cel
 *    @returns {Object} - An object representation of the cel
 */
function makeCel({ id, pixels, width, height, offsetX = 0, offsetY = 0 }) {
  const canvas = document.createElement("canvas");
  canvas.width = width;
  canvas.height = height;

  canvas
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
        return kind === 'background' ? this.background : kind === 'shadow' ? this.shadow : this.regular;
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
        if (toKind === 'background') {
            this.regular.push(...this.background); // move existing bg to regular
            this.background = [frame];
        } else {
            this.layer(toKind).push(frame);
        }
    }
}

window.editor = {
  canvas: null,
  running: false,

  init(canvasId) {
    const el = document.getElementById(canvasId);

    if (!el) {
      console.error(`Canvas element with id "${canvasId}" not found.`);
      return;
    }

    this.canvas = new fabric.Canvas(el);

    if (!this.canvas) {
      this.running = true;
      this.animate();
    }
  },
};
