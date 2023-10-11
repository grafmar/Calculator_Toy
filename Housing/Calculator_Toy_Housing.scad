use <Calculator_Toy_PCB.scad>

buttonPos = [
[2.5,2,"<"], [7.5,2,"0"], [12.5,2,">"],
[2.5,7,"7"], [7.5,7,"8"], [12.5,7,"9"],
[2.5,12,"4"],[7.5,12,"5"],[12.5,12,"6"],
[2.5,17,"1"],[7.5,17,"2"],[12.5,17,"3"]];

buttonChar = [
"1","2","3",
"4","5","6",
"7","8","9",
"*","0","#"];

pcbW=70;
pcbH=91;

thick=2;
clearance=0.3;

Calculator_Toy_PCB();
color("orange")OnOffSwitch();
color("orange")Keypad();
color("silver")Housing();
color("silver")BottomSlide_compl();

module BottomSlide_compl() {
    BottomSlide();
    translate([0,0,-5])cube([2,pcbH,5-1]);
    translate([pcbW-1,0,-5])cube([1,pcbH,5-1]);
    translate([(2+7)*2.54-0.5,0,-5])cube([1,30,5-1]);
}
module BottomSlide() {
    hull(){
        translate([-0.5-thick/2,-0.5-thick/2,-5.01+thick/2])cube([pcbW+1+2*thick/2,pcbH+1+thick/2,0.01]);
        translate([-0.5,-0.5-thick/2,-5.01])cube([pcbW+1,pcbH+1+thick/2,0.01]);
    }
}
module Housing() {
difference(){
    translate([-0.5-thick,-0.5-thick,-5])roundCube([pcbW+1+2*thick,pcbH+1+2*thick,14+thick+5],thick);

    translate([-0.5,-0.5,-5.01])cube([pcbW+1,pcbH+1,14+5]);
    
    // bottom slide
    translate([-0.5,-0.5-10,-1-5.01])cube([pcbW+1,pcbH+1+10,5]);
    hull()for(zz=[0,clearance])for(yy=[0,-10])for(i=[-1:1])translate([i*clearance,yy,zz])BottomSlide();
    
    // Display
    translate([(2+6)*2.54,(3+21)*2.54,0]){translate([-(27.5-4*2.54)/2-0.5*2.54,-0.5*2.54,0]){
        hull(){
            translate([0-0.5,5-0.5,14-0.1])cube([27.5+1,15+1,0.1]);
            translate([0-2*thick,5-2*thick,14+thick+0.1])cube([27.5+4*thick,15+4*thick,0.1]);
        }
    }}
    
    // USB
    translate([(2+17)*2.54,(3+15)*2.54,0]){
        color("#DDDDDD")translate([5.3-0.5*2.54-(12-7.5)/2,37.1-1.5*2.54,2.5+1.5-5/2])cube([12,9+20,9]);
    }
    
    // On/Off-Switch
    translate([(2+21)*2.54,(3+9)*2.54,0]){
        color("#0000DD")translate([-5,-5,0+3])cube([10,10,14+thick+1]);
    }
    
    // Keypad
    for(pos=buttonPos)translate([(2+pos.x-2)*2.54,(3+pos.y-2)*2.54,0])cube([4*2.54,4*2.54,2*14]);
}
}

module OnOffSwitch() {
    // On/Off-Switch
    color("#DDDDDD")translate([(2+21)*2.54,(3+9)*2.54,0]){
        for(a=[0:90:360-0.1])rotate([0,0,a])translate([5-clearance,-2,7+2+0.5])cube([2,4,13.5-9.5]);
            
        difference() {
            translate([-5+clearance,-5+clearance,7+2+0.5])cube([10-2*clearance,10-2*clearance,14+thick+0.5-(7+2+0.5)]);
            translate([-3/2-clearance,-2/2-clearance,0])cube([3+2*clearance,2+2*clearance,12.5]);
            // PowerSymbol
            translate([0,0,14+thick+0.5 - 1]){
                hull(){
                    translate([0,-1.5,0])cylinder(d=1,h=40,$fs=0.3);
                    translate([0,1.5,0])cylinder(d=1,h=40,$fs=0.3);
                }
                difference() {
                    $fs=.5;
                    cylinder(d=7,h=40);
                    cylinder(d=6,h=40);
                }
            }
        }
    }
}

module Keypad() {
    // Keypad
    color("#DDDDDD")for(pos=buttonPos)translate([(2+pos.x-2)*2.54,(3+pos.y-2)*2.54,5]){
        translate([2*2.54,2*2.54,-5])for(a=[0:90:360-0.1])rotate([0,0,a])translate([2*2.54-clearance-0.1,1,14-0.5-1])hull(){
            cube([2,2,1]);
            translate([0,0,-2])cube([0.1,2,0.1]);
        }
        difference() {
            translate([clearance,clearance,0])cube([4*2.54-2*clearance,4*2.54-2*clearance,14+thick+1-5]);
            translate([2*2.54,2*2.54,-0.01])cylinder(d1=5,d2=3.7,h=8-5,$fs=0.5);
            translate([2*2.54,2*2.54,14+thick-5])linear_extrude(height=10,center=false,convexity=10)text(pos[2],size=7, halign="center",valign="center");
        }
    }
}

module roundCube(dim,rad) {
    $fs=0.5;
    hull() {
        for(xx=[rad,dim.x-rad])for(yy=[rad,dim.y-rad])translate([xx,yy,0])cylinder(r=rad,h=dim.z);
    }
}
