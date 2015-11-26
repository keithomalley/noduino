function Player (x,y,w,h,c){
  this.x = x;
  this.y = y;
  this.width = w;
  this.height = h;
  this.temp_height = h;
  this.c = c;
  this.velY = 0;
  this.velX = 0;
  this.friction = 0.8;
  this.speed = 3;
  this.gravity = 0.2;
  this.jumping = false;
  this.grounded = false;
}

Player.prototype.update = function(context,slide,jump){
  if(jump == 1){
    if(!this.jumping && this.grounded){
      this.jumping = true;
      this.grounded = false;
      this.velY = -this.speed * 2;
    }
  }

  if(slide == 1){
    this.height = this.temp_height / 2;
  } else {
    this.height = this.temp_height;
  }


  if (this.velX < this.speed) {
    this.velX++;
  }

  if (this.x >= ((context.canvas.width / 2) -  this.width/2 )){
    this.velX = 0;
  }


  this.velX *= this.friction;
  this.velY += this.gravity;



} // end update


Player.prototype.draw = function(context){

  context.shadowBlur=10;
  context.shadowColor="rgba(0,0,0,0.2)";
  context.fillStyle=this.c;
  context.fillRect(this.x,this.y,this.width,this.height);

  context.shadowBlur=0;
}
