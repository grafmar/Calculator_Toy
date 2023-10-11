buttonPos = [
[2.5,2], [7.5,2], [12.5,2],
[2.5,7], [7.5,7], [12.5,7],
[2.5,12],[7.5,12],[12.5,12],
[2.5,17],[7.5,17],[12.5,17]];

pcbW=70;
pcbH=91;

Calculator_Toy_PCB();

module Calculator_Toy_PCB(holes=false) {
pcb(holes);
buttons();
buzzer();
switch();
display();
arduino();
}

module pcb(holes) {
    translate([0,0,-1])
    color("#DDAA00")
    difference() {
        cube([pcbW,pcbH,1]);
        if (holes) for(xx=[0:23])for(yy=[0:29])translate([(2+xx)*2.54,(3+yy)*2.54,0])cylinder(d=0.8,h=3,$fn=3,center=true);
    }
}

module buttons() {
    for(pos=buttonPos)translate([(2+pos.x)*2.54,(3+pos.y)*2.54,0])button();
}

module button() {
    $fs=0.5;
    //translate([1.5*2.54,2.54,0]){
        color("#222222")translate([0,0,1])cylinder(d=3.5,h=8-1);
        color("#AAAAAA")translate([-3,-3,3])cube([6,6,0.5]);    
        color("#222222")translate([-3,-3,0])cube([6,6,3]);
        color("#AAAAAA")for(i=[-1,1])translate([-(3*2.54)/2,i*2.54,0])cube([3*2.54,0.5,1]);    
    //}
}

module buzzer() {
    translate([(2+20)*2.54,(3+2)*2.54,0])difference() {
        color("#222222")cylinder(d=17,h=8);
        translate([0,0,5])cylinder(d=2,h=8,$fs=0.5);
    }
}

module switch(){
    translate([(2+21)*2.54,(3+9)*2.54,0]){
        color("#222222")translate([0,0,2])cube([7,7,4],center=true);
        color("#DDDDDD")translate([0,0,2+4])cube([7,7,4],center=true);
        color("#0000DD")translate([0,0,2+8])cube([3.5,3.5,4],center=true);
    }
}

module display(){
    translate([(2+6)*2.54,(3+21)*2.54,0]){
        translate([-(27.5-4*2.54)/2-0.5*2.54,-0.5*2.54,0]){
            color("#000088")translate([0,0,11])cube([27.5,28,1]);
            color("#222222")translate([0,5,12])cube([27.5,15,2]);
        }
        color("#222222")translate([-0.5*2.54,-0.5*2.54,0])cube([4*2.54,2.54,11]);
    }
}

module arduino(){
    translate([(2+17)*2.54,(3+15)*2.54,0]){
        color("#222222")translate([-0.5*2.54,-0.5*2.54,0])cube([2.54,15*2.54,2.5]);   
        color("#222222")translate([(6-0.5)*2.54,-0.5*2.54,0])cube([2.54,15*2.54,2.5]);   
        color("#000088")translate([-0.5*2.54,-1.5*2.54,2.5])cube([7*2.54,17*2.54,1]);
        color("#DDDDDD")translate([5.3-0.5*2.54,37.1-1.5*2.54,2.5+1.5])cube([7.5,9,4]);
    }
}
