/**
 *    Frame class extends FabricImage to represent a frame in the canvas
 *
 *    @param kind - The kind of frame: 'regular', 'shadow', or 'background'
 *    @param selectable - Whether the frame is selectable (default: false)
 *    @param evented - Whether the frame is evented (default: false)
 *    @returns {Object} - An object representation of the frame
 */
class Frame extends fabric.FabricImage {
  static type = "frame";

  constructor(element, options = {}) {
    super(element, options);
    this.kind = options.kind ?? "regular"; // or 'shadow' or 'background'
    this.selectable = false;
    this.evented = false;
  }
}

fabric.classRegistry.setClass(Frame);

/**
 *    Creates a new frame with the given properties
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

