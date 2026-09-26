$fn=64;
cube([85, 111, 2]);
translate([0, 55, 50])
cube([64, 2, 10]);
translate([0, 57, 22])
cube([70, 5, 2]);
translate([0, 57, 26])
cube([70, 5, 2]);
translate([0, 106, 22])
cube([70, 5, 2]);
translate([0, 106, 26])
cube([70, 5, 2]);
translate([-2, 20 , 60])
cube([82, 93, 2]);
translate([-2, 0 ,62])
cube([2, 113, 40]);
translate([-2, 0, 102])
cube([87, 113, 2]);
translate([40, 55.5, 62])
cylinder(h = 30, r = 10);
translate([-2, 0, 60])
cube([62, 20, 2]);
translate([-2, 111, 0]){
difference(){
    cube([82 , 2, 102]);
    translate([74, -1, 20]){ 
    cube([3.2, 4, 10]);
        }
    }
}
translate([0, 55, 2]){
difference(){
    cube([80, 2, 48]);
    translate([72, -1, 18]){
    cube([3.2, 4, 10]);
            }
       }
}
translate([-2, -2, 0])
cube([87, 2, 104]);
translate([-2, 0, 0]){
difference(){
    cube([2, 111, 60]);
    translate([-1, 83, 24]){
    cube([4, 18, 10]);
        }
    }
}
translate([0, 12, 2])
cube([10, 2, 1.2]);
translate([0, 38, 2])
cube([10, 2, 1.2]);
translate([0, 12, 3.2])
cube([10, 28, 2]);
translate([83, 0, 97])
cube([2, 113, 5]);
translate([83, 0, 2])
cube([2, 113, 4]);
translate([80, 111, 0])
cube([5, 2, 2]);
translate([78, 0, 97])
cube([2, 111, 5]);
