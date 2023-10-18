difference(){
    union(){
        cube([17,70,1]);
        cube([1,70,4]);
    }
    for(i=[-1,1])translate([16/2+1,70/2+i*(70/2-10),0])cylinder(d=1.5,h=3,center=true,$fs=.5);
}