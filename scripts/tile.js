class Tile {
  constructor(x, y, size, color) {
    this.pos = { x: x, y: y };
    this.size = size;
    this.color = color;
  }

  draw(ctx) {
    ctx.fillStyle = this.color;
    ctx.fillRect(this.pos.x, this.pos.y, this.size, this.size);
    
  }
}
