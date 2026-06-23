import { FabricImage, classRegistry } from 'fabric';

class Frame extends FabricImage {
    constructor(objects, options = {}) {
        super(objects, options);
        this.type = 'layers';
        this.order = 1;
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