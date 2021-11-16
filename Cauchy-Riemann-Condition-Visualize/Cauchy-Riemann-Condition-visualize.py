from manimlib import *
from manimlib import animation

'''
class CR_Visualize(Scene):
    def construct(self):
        # Complex map
        inner_frame_width = FRAME_WIDTH / 2
        left_frame = PictureInPictureFrame()
        left_frame.set_width(inner_frame_width)
        
        c_grid_len = FRAME_WIDTH/3
        c_grid_range = [-4, 4, 1]
        buff = FRAME_WIDTH/10
        c_grid = ComplexPlane(x_range = c_grid_range, y_range = c_grid_range, width = c_grid_len, height = c_grid_len)
        c_grid.to_edge(LEFT, buff)
        left_frame.add(c_grid)

        moving_c_grid = c_grid.copy()
        moving_c_grid.to_edge(RIGHT, buff)
        moving_c_grid.prepare_for_nonlinear_transform()
        # c_grid.set_stroke(BLUE_E, 1)
        # c_grid.add_coordinate_labels(font_size=24)
        complex_map_words = TexText("""
            Or thinking of the plane as $\\mathds{C}$,\\\\
            this is the map $z \\rightarrow z^2$
        """)
        complex_map_words.to_corner(UR)
        complex_map_words.set_stroke(BLACK, 5, background=True)

        self.play(
            Write(left_frame, run_time=2),
            FadeIn(moving_c_grid),
            FadeIn(complex_map_words),
        )
        self.wait()
        
        self.play(
            moving_c_grid.animate.apply_function(def_R3_func(lambda z: z**2), about_point = moving_c_grid.get_center()),
            run_time=6,
        )
        self.wait(2)

def def_R3_func(function):
    def R3_func(point):
        x, y, z = point
        xy_complex = function(complex(x, y))
        return [
            xy_complex.real,
            xy_complex.imag,
            z
        ]
    return R3_func
'''

# global parameters
c_grid_len = FRAME_WIDTH # /3
c_grid_range = [-10, 10, 1]
buff = 0 # FRAME_WIDTH/10
animation_time = 0.1
interval_time = 0.1
arrow_max_tip_length_to_length_ratio = 0.25

base_point_x = 1.
base_point_y = 2.
dx = 0.2
dy = 0.2

class CR_Visualize_left_side(Scene):
    def construct(self):
        frame_scale = 0.5
        dot_scale = 0.3
        text_scale = 0.2

        # Complex map
        c_grid = ComplexPlane(x_range = c_grid_range, y_range = c_grid_range, width = c_grid_len, height = c_grid_len)
        c_grid.to_edge(LEFT, buff)
        origin = c_grid.get_origin()

        base_point = c_grid.coords_to_point(base_point_x, base_point_y)
        base_dot = Dot(base_point)

        self.play(
            Write(c_grid, run_time=animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(base_dot, run_time=animation_time),
        )
        self.wait(interval_time)

        frame = self.camera.frame
        base_elements = VGroup(c_grid, base_dot)
        self.play(
            base_elements.animate.shift(-base_point),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            frame.animate.set_height(frame_scale),
            base_dot.animate.scale(dot_scale),
            run_time=animation_time
        )
        self.wait(interval_time)

        base_point = base_dot.get_center()
        dx_point = c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = c_grid.coords_to_point(base_point_x, base_point_y + dy)
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=GREEN, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=RED, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dx_label = TexText("$\Delta x$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(v_dx.end, DOWN*frame_scale * text_scale)
        v_dx_label.set_color(GREEN)
        v_dy_label = TexText("$\Delta y$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(v_dy.end, LEFT*frame_scale * text_scale)
        v_dy_label.set_color(RED)

        self.play(
            Write(v_dx),
            Write(v_dx_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(v_dy),
            Write(v_dy_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.wait(interval_time)

class CR_Visualize_right_side(Scene):
    def construct(self):
        frame_scale = 1
        dot_scale = 0.3
        text_scale = 0.1

        # Complex map
        moving_c_grid = ComplexPlane(x_range = c_grid_range, y_range = c_grid_range, width = c_grid_len, height = c_grid_len)
        moving_c_grid.to_edge(RIGHT, buff)
        moving_c_grid.prepare_for_nonlinear_transform()

        base_point = moving_c_grid.coords_to_point(base_point_x, base_point_y)
        base_dot = SmallDot(base_point)

        self.play(
            Write(moving_c_grid, run_time=animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(base_dot, run_time=animation_time),
        )
        self.wait(interval_time)

        dx_point = moving_c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = moving_c_grid.coords_to_point(base_point_x, base_point_y + dy)
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=GREEN, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=RED, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)

        self.play(
            Write(v_dx, run_time=animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(v_dy, run_time=animation_time),
        )
        self.wait(interval_time)

        base_elements = VGroup(moving_c_grid, base_dot, v_dx, v_dy)
        
        self.play(
            base_elements.animate.apply_complex_function(lambda z: z**2),
            run_time=animation_time,
        )
        self.wait(interval_time)

        base_point = base_dot.get_center()
        frame = self.camera.frame
        self.play(
            base_elements.animate.shift(-base_point),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            #frame.animate.set_height(frame_scale),
            base_dot.animate.scale(dot_scale),
            run_time=animation_time
        )
        self.wait(interval_time)

        base_point = base_dot.get_center()
        v_dx_label = TexText("$\Delta x$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(v_dx.end, DOWN*frame_scale * text_scale)
        v_dx_label.set_color(GREEN)
        v_dy_label = TexText("$\Delta y$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(v_dy.end, LEFT*frame_scale * text_scale)
        v_dy_label.set_color(RED)

        self.play(
            Write(v_dx_label, run_time=animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(v_dy_label, run_time=animation_time),
        )
        self.wait(interval_time)

        self.wait(interval_time)