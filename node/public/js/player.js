function Player (x,y,w,h,c){
  this.x = x;
  this.y = y;
  this.w = w;
  this.h = h;
  this.c = c;
}

Player.prototype.draw = function(context,slide,jump){

  context.shadowBlur=10;
  context.shadowColor="rgba(0,0,0,0.2)";
  context.fillStyle=this.c;

  if(this.y < (context.canvas.height - this.h )){
    this.y += 5;
  }

  if(jump == 1){
    this.y -= 20;
    context.fillRect(this.x,this.y,this.w,this.h);
  } else if(slide == 1){
    context.fillRect(this.x,this.y + this.w,this.h,this.w);
  } else {
    context.fillRect(this.x,this.y,this.w,this.h);
  }

  context.shadowBlur=0;
}
