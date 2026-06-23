import { FabricImage, classRegistry } from 'fabric';

class Frame extends FabricImage {
    /*
        Frame class extends FabricImage to represent a frame in the canvas

        @kind - The kind of frame: 'regular', 'shadow', or 'background'
        @order - The order of the frame indexed from 0
        @layerId - The layer ID associated with the frame
    */
    static type = 'frame';

    constructor(element, options = {}) {
        super(element, options);
        this.kind = options.kind ?? 'regular'; // or 'shadow' or 'background'
        this.order = options.order ?? 0;
        this.layerId = options.layerId ?? null;
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
}