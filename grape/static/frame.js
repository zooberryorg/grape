class Frame extends fabric.Object {
    constructor(options) {
        super(options);
        this.type = 'frame';
        this.order = 0;
        this.width = 100;
        this.height = 100;
        this.fill = 'rgba(0,0,0,0.1)';
        this.offsetX = 0;
        this.offsetY = 0;
    }
}

class Layers extends fabric.Group {
    constructor(objects, options) {
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