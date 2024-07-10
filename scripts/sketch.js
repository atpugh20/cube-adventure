/* CANVAS SETUP */

const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");
const cW = (canvas.width = Math.floor(window.innerWidth * 0.8));
const cH = (canvas.height = (cW * 3) / 4);
canvas.style.backgroundColor = "white";

/* GLOBALS */

const rows = 30;
const cols = 40;
const squareSize = cW / cols;
const player = new Player(50, 50, squareSize, "rgb(0,0,255)");
const enemies = [
  new Enemy(100, 100, squareSize, "rgb(255,0,0)"),
  new Enemy(150, 200, squareSize, "rgb(255,0,0)"),
  new Enemy(cols - 2, rows - 2, squareSize, "rgb(255,0,0)"),
];

var grid = [];
var frame = 0;

/* MAIN */

window.addEventListener("keydown", (e) => {
  const k = e.key;
  if (k === "w" || k === "a" || k === "s" || k === "d")
    player.movement.keys[k] = 1;
  if (k === " ") player.attacking = true;
});

window.addEventListener("keyup", (e) => {
  const k = e.key;
  if (k === "w" || k === "a" || k === "s" || k === "d")
    player.movement.keys[k] = 0;
  if (k === " ") {
    player.attacking = false;
    player.attackInterval = 0;
  }
});
setInterval(draw, 1000 / 60);

/* FUNCTIONS */

function setup() {}

function draw() {
  frame++;
  clearCanvas();
  for (let y = 0; y < rows; y++) {
    for (let x = 0; x < cols; x++) {
      ctx.fillStyle = "black";
      if (x === 0 || x === cols - 1 || y === 0 || y === rows - 1)
        ctx.fillStyle = "green";

      ctx.fillRect(x * squareSize, y * squareSize, squareSize, squareSize);
    }
  }
  player.update();
  player.attack(ctx);
  player.draw(ctx);
  for (let enemy of enemies) {
    enemy.update(player.pos);
    enemy.draw(ctx);
  }
}

// Erases what was drawn on the canvas
function clearCanvas() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.fillStyle = "black";
  ctx.fillRect(0, 0, canvas.width, canvas.height);
}
