class Player {
  constructor(x, y, size, color) {
    this.pos = { x: x, y: y };
    this.size = size;
    this.color = color;
    this.dir = { x: 0, y: 1 };
    this.movement = {
      time: 0,
      keys: { w: 0, a: 0, s: 0, d: 0 },
    };
    this.attacking = false;
  }

  draw(ctx) {
    if (this.dir.y === -1) {
      ctx.fillStyle = this.color;
      ctx.fillRect(
        this.pos.x * this.size,
        this.pos.y * this.size,
        this.size,
        this.size
      );
    } else {
      const image = new Image();
      if (this.dir.x === -1) {
        image.src = "./assets/textures/player/playerLeft.png";
      } else if (this.dir.x === 1) {
        image.src = "./assets/textures/player/playerRight.png";
      } else {
        image.src = "./assets/textures/player/playerFront.png";
      }
      ctx.drawImage(
        image,
        this.pos.x * this.size,
        this.pos.y * this.size,
        this.size,
        this.size
      );
    }
  }

  update() {
    this.movement.time++;
    if (this.movement.time % 2 === 0) {
      if (this.movement.keys.w) {
        this.changeDirection("w");
        this.move("w");
      }
      if (this.movement.keys.a) {
        this.changeDirection("a");
        this.move("a");
      }
      if (this.movement.keys.s) {
        this.changeDirection("s");
        this.move("s");
      }
      if (this.movement.keys.d) {
        this.changeDirection("d");
        this.move("d");
      }
    }
  }

  changeDirection(key) {
    if (key === "w") this.dir = { x: 0, y: -1 };
    if (key === "s") this.dir = { x: 0, y: 1 };
    if (key === "a") this.dir = { x: -1, y: 0 };
    if (key === "d") this.dir = { x: 1, y: 0 };
  }

  move(key) {
    if (key === "w" && this.pos.y > 1) this.pos.y--;
    if (key === "s" && this.pos.y < rows - 2) this.pos.y++;
    if (key === "a" && this.pos.x > 1) this.pos.x--;
    if (key === "d" && this.pos.x < cols - 2) this.pos.x++;
  }

  attack(ctx) {
    if (this.attacking === false) {
      this.attacking = true;
      ctx.fillStyle = "grey";
      ctx.fillRect(
        (this.pos.x + this.dir.x) * this.size,
        (this.pos.y + this.dir.y) * this.size,
        this.size,
        this.size
      );
    }
  }
}
