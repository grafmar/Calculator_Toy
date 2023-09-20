//include <Calculator_Toy_PCB.scad>

buttonPos = [
[2.5,2], [7.5,2], [12.5,2],
[2.5,7], [7.5,7], [12.5,7],
[2.5,12],[7.5,12],[12.5,12],
[2.5,17],[7.5,17],[12.5,17]];

pcbW=70;
pcbH=91;

thick=2;

difference(){
    translate([-0.5-thick,-0.5-thick])roundCube([pcbW+1+2*thick,pcbH+1+2*thick,14+thick],thick);

    translate([-0.5,-0.5,-0.01])cube([pcbW+1,pcbH+1,14]);
}

module roundCube(dim,rad) {
    $fs=0.5;
    hull() {
        for(xx=[rad,dim.x-rad])for(yy=[rad,dim.y-rad])translate([xx,yy,0])cylinder(r=rad,h=dim.z);
    }
}
