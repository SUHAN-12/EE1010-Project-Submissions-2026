translate([0, -5, 0])
cube([194.2, 89, 2]);

translate([87, 0, 2])
cube([3.2, 84, 55]);

translate([-2, -5, 0])
difference() {
    cube([2, 89, 86]);
    translate([-2, 52, 6])
    cube([6, 20, 20]);
}

translate([-2, -5, 86])
difference() {
    cube([196.2, 89, 2]);
    translate([166.2, 7, -2])
    cube([27, 74, 6]);
}

translate([-2, 84, 0])
difference() {
    cube([196.2, 2, 88]);

    translate([117.2, -2, 70])
    rotate([-90, 0, 0])
    cylinder(h = 6, d = 28, $fn = 60);

    translate([117.2, -2, 30])
    rotate([-90, 0, 0])
    cylinder(h = 6, d = 10, $fn = 60);
}

translate([194.2, 0, 0])
cube([2, 86, 88]);

translate([0, 12, 2])
cube([87, 2, 4]);

translate([90.2, 0, 50])
cube([5, 84, 2]);

translate([156.2, 0, 50])
cube([38, 84, 2]);

translate([161.2, 0, 52])
cube([2, 84, 5]);

translate([0, -5, 2])
cube([196.2, 2, 5]);

translate([0, -5, 82])
cube([196.2, 2, 4]);

translate([194.2, -5, 86])
cube([2, 5, 2]);

translate([-7, -5, 50])
cube([5, 91, 2]);

translate([-13, 86, 52])
rotate([90, 0, 0])
difference() {
    intersection() {
        cylinder(h = 91, d = 14, $fn = 100);
        translate([-7, -7, 0])
        cube([14, 7, 93]);
    }

    translate([0, 0, 0])
    cylinder(h = 93, d = 12, $fn = 100);
}
translate([0, 86, 0])
cube([20, 20, 2]);
translate([10, 97, 2])
cylinder(h= 30, d = 10, $fn=60);
