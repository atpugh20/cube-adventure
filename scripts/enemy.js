class Enemy {
  constructor(x, y, size, color) {
    this.pos = { x: x, y: y };
    this.size = size;
    this.color = color;
    this.frame = 0;
  }

  draw(ctx) {
    const image = new Image();
    image.src = "./assets/textures/enemies/enemy1/enemy.png";
    ctx.drawImage(
      image,
      this.pos.x * this.size,
      this.pos.y * this.size,
      this.size,
      this.size
    );
  }

  update(playerPos) {
    this.frame++;
    const xDiff = playerPos.x - this.pos.x;
    const yDiff = playerPos.y - this.pos.y;
    const distance = Math.sqrt(xDiff ** 2 + yDiff ** 2);
    if (distance < 10) {
      this.pursue(xDiff, yDiff);
    } else {
      this.move();
    }
  }

  move() {
    if (this.frame % 20 === 0) {
      const direction = Math.floor(Math.random() * 4);
      if (direction === 0) {
        if (this.pos.x < cols - 2) {
          this.pos.x++;
        } else {
          this.pos.x--;
        }
      } else if (direction === 1) {
        if (this.pos.y > 1) {
          this.pos.y--;
        } else {
          this.pos.y++;
        }
      } else if (direction === 2) {
        if (this.pos.x > 1) {
          this.pos.x--;
        } else {
          this.pos.x++;
        }
      } else {
        if (this.pos.y < rows - 2) {
          this.pos.y++;
        } else {
          this.pos.y--;
        }
      }
    }
  }

  pursue(xDiff, yDiff) {
    if (this.frame % 3 === 0) {
      if (Math.abs(xDiff) >= Math.abs(yDiff)) {
        this.pos.x += Math.sign(xDiff);
      } else {
        this.pos.y += Math.sign(yDiff);
      }
    }
  }
}
