trellis_button_side = 10.5;
trellis_button_grid = 15;
trellis_button_squish = 2;

trellis_rows = 4;
trellis_cols = 4;

tbt_side = 15.5;
tbt_grid = 25;


module roundedSquare(length, width, radius) {
    
    //translate([radius - (side_length / 2), radius - (side_length / 2), 0])
    translate([radius, radius, 0])
    hull() {
        circle(r=radius);
        
        translate([length - 2 * radius,0,0])
        circle(r=radius);
        
        translate([length - 2 * radius, width - 2 * radius,0])
        circle(r=radius);
        
        translate([0, width - 2 * radius,0])
        circle(r=radius);
    }
}

module button(h, w, r) {
    linear_extrude(height = h) roundedSquare(h, w, r);
}

module buttons(h, w, r, s, rows, cols) {
    
    for(y = [0:rows-1]) {
        for(x = [0:cols-1]) {
            translate([x * s, y * s, 0])
            button(h,w,r);
        }
    }
    
}

module tft() {
    // overall 46x34 (56x34)
    // screen 35x28
    translate([0,0,-1]) {
        color("Red")
        linear_extrude(1)
        square([80,50]);
        
        color("Black")
        linear_extrude(4)
        translate([7.5,0,1])
        square([70,50]);
    }
}

module knob(c) {
    
    translate([0,0,3]) {
        translate([0,0,-10])
    cylinder(h=10, r=3.5);
    color("Grey")
    cylinder(h=18,r=6);
    translate([0,0,18])
    color(c)
    cylinder(h=1,r=6);
    }
}

module knobs() {
    knob("Red");
    
    translate([30,0,0])
    knob("Blue");
    
    translate([60,0,0])
    knob("Green");
    
    translate([90,0,0])
    knob("Black");
    
    
}
        
$fn=100;

module trellis() {
    buttons(trellis_button_side, trellis_button_side, 2, trellis_button_grid, 4, 8);
}

module control_buttons() {
    buttons(tbt_side, tbt_side, 2, tbt_grid, 2, 2);
}

module panel() {
    color("White")
    cube([260, 105, 2.5]);
}

projection()
difference() {
    translate([-10, -20, 0.1])
    panel();

    translate([0, - (tbt_side/2 + tbt_grid/2),0])
    translate([0, (trellis_button_side/2 + trellis_button_grid * 3/2), 0])
    control_buttons();

    translate([tbt_side * 2 + tbt_grid, 0, 0])
    trellis();

    translate([235,-15,0])
    rotate([0,0,90])
    tft();

    translate([70,70,0])
    knobs();
}
