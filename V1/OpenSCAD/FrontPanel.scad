trellis_button_side = 12;
trellis_button_grid = 15;
trellis_button_squish = 2;

trellis_rows = 4;
trellis_cols = 8;

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

module trellis() {
    
    module buttonGrid() {
        // the bottom has slightly larger holes to allow for the 
        // button squish
        
        offset = (trellis_button_grid - trellis_button_side) / 2;
        squish_offset = offset - (trellis_button_squish / 2);
        
        //linear_extrude(height = 1)
        difference() {
            square([trellis_cols * trellis_button_grid, trellis_rows * trellis_button_grid]);
            for(i = [0:trellis_cols-1]) {
                for(j = [0:trellis_rows-1]) {
                    translate([squish_offset + i * trellis_button_grid, squish_offset + j * trellis_button_grid, 0])
                    roundedSquare(trellis_button_side+trellis_button_squish, trellis_button_side+trellis_button_squish, 2);
                }
            }
        }
        
        translate([0,0,1])
        //linear_extrude(height = 2)
        difference() {
            square([trellis_cols * trellis_button_grid, trellis_rows * trellis_button_grid]);
            for(i = [0:trellis_cols-1]) {
                for(j = [0:trellis_rows-1]) {
                    translate([offset + i * trellis_button_grid, offset + j * trellis_button_grid, 0])
                    roundedSquare(trellis_button_side, trellis_button_side, 2);
                }
            }
        }
    }
    
    // put holes in a grid to allow mounting screws
    difference() {
        buttonGrid();
        translate([15,30,-0.1])
        cylinder(h=4, r=0.75);
        translate([45,30,-0.1])
        cylinder(h=4, r=0.75);
        translate([75,30,-0.1])
        cylinder(h=4, r=0.75);
        translate([105,30,-0.1])
        cylinder(h=4, r=0.75);
    }
}

module twoByTwo() {
    // button is 15sq, separation is 10, edge is 5
    difference() {
        square([50,50]);
        for(i = [0:1]) {
            for(j = [0:1]) {
                translate([5 + i * 25, 5 + j * 25, 0])
                roundedSquare(15,15,2);
            }
        }
    }
}

module tft() {
    // overall 46x34 (56x34)
    // screen 35x28
    square([56,34]);
    color("Black")
    translate([11,3,1])
    square([35,28]);
}

module knobs() {
    for(i = [0:1]) {
        for(j = [0:1]) {
            color("Green")
            translate([5 + i * 20, 5 + j * 25, 0])
            cylinder(h=15, r=5);
        }
    }
}
        

$fn=100;
translate([0,58,0])
trellis();
/**
twoByTwo();
translate([85,0,0])
rotate([0,0,90])
tft();

translate([95 - 7.5,7.5,0])
knobs();
**/