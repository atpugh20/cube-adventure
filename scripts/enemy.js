class Enemy {
  constructor(x, y, size, color) {
    this.pos = { x: x, y: y };
    this.vel = { x: 0, y: 0 };
    this.acc = { x: 0, y: 0 };
    this.size = size;
    this.color = color;
    this.frame = 0;
    this.direction = Math.floor(Math.random() * 4);
    this.moveInterval = Math.floor(Math.random() * 50);
    this.stopInterval = 0;
  }

  draw(ctx) {
    const image = new Image();
    image.src = "./assets/textures/enemies/enemy1/enemy.png";
    ctx.drawImage(image, this.pos.x, this.pos.y, this.size, this.size);
  }

  update(playerPos) {
    this.frame++;
    const xDiff = playerPos.x - this.pos.x;
    const yDiff = playerPos.y - this.pos.y;
    const distance = Math.sqrt(xDiff ** 2 + yDiff ** 2);
    if (distance < 100) {
      this.pursue(xDiff, yDiff);
    } else {
      if (this.stopInterval === 200) {
        this.direction = Math.floor(Math.random() * 4);
        this.stopInterval = 0;
        this.moveInterval = 0;
      }
      if (this.moveInterval < 100) this.move(this.direction);
      this.stopInterval++;
      this.moveInterval++;
    }
  }

  move(dir) {
    if (dir === 0) {
      if (this.pos.x < cW - squareSize - this.size) {
        this.pos.x++;
      } else {
        this.direction = 2;
        this.pos.x--;
      }
    } else if (dir === 1) {
      if (this.pos.y > squareSize) {
        this.pos.y--;
      } else {
        this.direction = 3;
        this.pos.y++;
      }
    } else if (dir === 2) {
      if (this.pos.x > squareSize) {
        this.pos.x--;
      } else {
        this.direction = 0;
        this.pos.x++;
      }
    } else {
      if (this.pos.y < cH - squareSize - this.size) {
        this.pos.y++;
      } else {
        this.direction = 1;
        this.pos.y--;
      }
    }
  }

  pursue(xDiff, yDiff) {
    if (Math.abs(xDiff) >= Math.abs(yDiff)) {
      this.pos.x += Math.sign(xDiff) * 2;
    } else {
      this.pos.y += Math.sign(yDiff) * 2;
    }
  }
}
