import { FabricImage, classRegistry } from "fabric";

class Frame extends FabricImage {
  /*
        Frame class extends FabricImage to represent a frame in the canvas

        @kind - The kind of frame: 'regular', 'shadow', or 'background'
        @order - The order of the frame indexed from 0
        @layerId - The layer ID associated with the frame
    */
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

function makeCel({id, pixels, width, height, offsetX = 0, offsetY = 0}) {
    const canvas = document.createElement("canvas");
    canvas.width = width;
    canvas.height = height;

    canvas.getContext("2d").putImageData(
        new ImageData(new Uint8ClampedArray(pixels), width, height), 0, 0
    );
    
    return { id, source, width, height, offsetX, offsetY };
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
