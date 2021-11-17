from manimlib import *

# global parameters
c_grid_len = FRAME_WIDTH # /3
c_grid_range = [-10, 10, 1]
buff = 0 # FRAME_WIDTH/10
animation_time = 1
interval_time = 0.5
arrow_max_tip_length_to_length_ratio = 0.25
arrow_stroke_width = 2

base_point_x = 1.
base_point_y = 2.
dx = 0.2
dy = 0.2

class CR_Visualize_left_side(Scene):
    def construct(self):
        frame_scale = 0.6
        dot_scale = 0.15
        text_scale = 0.2

        # Complex map
        c_grid = ComplexPlane(x_range = c_grid_range, y_range = c_grid_range, width = c_grid_len, height = c_grid_len)
        c_grid.to_edge(LEFT, buff)
        origin = c_grid.get_origin()

        # base point
        base_point = c_grid.coords_to_point(base_point_x, base_point_y)
        base_dot = Dot(base_point)

        self.play(
            Write(c_grid, run_time=2*animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(base_dot, run_time=animation_time),
        )
        self.wait(interval_time)
        
        ## sync point 1 - write coordinate
        ## 3 t1 + 2 t2 used
        ## (t1 = animation_time, t2 = interval_time)

        # dx, dy
        dx_point = c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = c_grid.coords_to_point(base_point_x, base_point_y + dy)
        dx_dot = Dot(dx_point, color=GREEN)
        dy_dot = Dot(dy_point, color=RED)
        
        self.play(
            Write(dx_dot),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(dy_dot),
            run_time=animation_time
        )
        self.wait(interval_time)

        ## sync point 2 - dx and dy drawn
        ## 2 t1 + 2 t2

        # the other scene is being transformed, so just wait
        self.wait(4*animation_time)
        self.wait(interval_time)

        ## sync point 3 - transformation applied
        ## 4 t1 + t2

        # shift the camera and zoom in
        frame = self.camera.frame
        base_elements = VGroup(c_grid, base_dot, dx_dot, dy_dot)
        self.play(
            base_elements.animate.shift(-base_point),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            frame.animate.set_height(frame_scale),
            base_dot.animate.scale(dot_scale),
            dx_dot.animate.scale(dot_scale),
            dy_dot.animate.scale(dot_scale),
            run_time=animation_time
        )
        self.wait(interval_time)

        ## sync point 4 - camera shifted and zoomed
        # 2 t1 + 2 t2

        # arrows and labels
        base_point = base_dot.get_center()
        dx_point = dx_dot.get_center()
        dy_point = dy_dot.get_center()
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=GREEN, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=RED, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dx_label = TexText("$\Delta x$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(dx_point, DOWN*(frame_scale * text_scale))
        v_dx_label.set_color(GREEN)
        v_dy_label = TexText("$\Delta y$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(dy_point, LEFT*(frame_scale * text_scale))
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

        ## sync point 5 - vectors and labels
        # 2 t1 + 2 t2

        # moving dot
        moving_dot = Dot(base_point, color=YELLOW)
        moving_dot.scale(0.5*dot_scale)
        self.play(
            FadeIn(moving_dot),
            run_time=0.5*animation_time
        )
        self.play(
            moving_dot.animate.move_to(dx_point),
            run_time=animation_time
        )
        self.play(
            FadeOut(moving_dot),
            run_time=0.5*animation_time
        )
        self.wait(interval_time)

        moving_dot.move_to(base_point)
        self.play(
            FadeIn(moving_dot),
            run_time=0.5*animation_time
        )
        self.play(
            moving_dot.animate.move_to(dy_point),
            run_time=animation_time
        )
        self.play(
            FadeOut(moving_dot),
            run_time=0.5*animation_time
        )
        self.wait(interval_time)

        ## sync point 6 - moving point
        # 4 t1 + 2 t2

#########################################################################################

class CR_Visualize_right_side(Scene):
    def construct(self):
        frame_scale = 1.2
        dot_scale = 0.15
        text_scale = 0.2

        # Complex map
        moving_c_grid = ComplexPlane(x_range = c_grid_range, y_range = c_grid_range, width = c_grid_len, height = c_grid_len)
        moving_c_grid.to_edge(RIGHT, buff)
        moving_c_grid.prepare_for_nonlinear_transform()

        # base point
        base_point = moving_c_grid.coords_to_point(base_point_x, base_point_y)
        base_dot = SmallDot(base_point)

        self.play(
            Write(moving_c_grid, run_time=2*animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(base_dot, run_time=animation_time),
        )
        self.wait(interval_time)

        ## sync point 1 - write coordinate
        ## 3 t1 + 2 t2 used

        # dx, dy
        dx_point = moving_c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = moving_c_grid.coords_to_point(base_point_x, base_point_y + dy)
        dx_dot = SmallDot(dx_point, color=GREEN)
        dy_dot = SmallDot(dy_point, color=RED)

        self.play(
            Write(dx_dot),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(dy_dot),
            run_time=animation_time
        )
        self.wait(interval_time)

        ## sync point 2 - dx and dy drawn
        ## 2 t1 + 2 t2

        # group altogether to apply transformation
        base_elements = VGroup(moving_c_grid, base_dot, dx_dot, dy_dot)
        
        # core transformation
        self.play(
            base_elements.animate.apply_complex_function(lambda z: z**2),
            run_time=4*animation_time,
        )
        self.wait(interval_time)

        ## sync point 3 - transformation applied
        # 4 t1 + t2

        # shift the camera and zoom in
        base_point = base_dot.get_center()
        frame = self.camera.frame
        self.play(
            base_elements.animate.shift(-base_point),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            frame.animate.set_height(frame_scale),
            base_dot.animate.scale(dot_scale),
            dx_dot.animate.scale(dot_scale),
            dy_dot.animate.scale(dot_scale),
            run_time=animation_time
        )
        self.wait(interval_time)

        ## sync point 4 - camera shifted and zoomed
        # 2 t1 + 2 t2

        # arrows and labels
        base_point = base_dot.get_center()
        dx_point = dx_dot.get_center()
        dy_point = dy_dot.get_center()
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=GREEN, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=RED, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dx_label = TexText("$\Delta_x f$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(dx_dot.get_center(), RIGHT*(frame_scale * text_scale * 2))
        v_dx_label.set_color(GREEN)
        v_dy_label = TexText("$\Delta_y f$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(dy_dot.get_center(), LEFT*(frame_scale * text_scale * 2))
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

        ## sync point 5 - vectors and labels
        # 2 t1 + 2 t2

        # moving dot
        moving_dot = Dot(base_point, color=YELLOW)
        moving_dot.scale(dot_scale)
        self.play(
            FadeIn(moving_dot),
            run_time=0.5*animation_time
        )
        self.play(
            moving_dot.animate.move_to(dx_point),
            run_time=animation_time
        )
        self.play(
            FadeOut(moving_dot),
            run_time=0.5*animation_time
        )
        self.wait(interval_time)

        moving_dot.move_to(base_point)
        self.play(
            FadeIn(moving_dot),
            run_time=0.5*animation_time
        )
        self.play(
            moving_dot.animate.move_to(dy_point),
            run_time=animation_time
        )
        self.play(
            FadeOut(moving_dot),
            run_time=0.5*animation_time
        )
        self.wait(interval_time)

        ## sync point 6 - moving point
        # 4 t1 + 2 t2

        # analyze u, v
        v_u_dx_point = [dx_point[0], base_point[1], 0.]
        v_u_dy_point = [dy_point[0], base_point[1], 0.]
        v_u_dx = Arrow(start=base_point, end=v_u_dx_point, buff=0, stroke_color=BLUE, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_dy = Arrow(start=base_point, end=v_u_dy_point, buff=0, stroke_color=ORANGE, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_dx_label = TexText("$\Delta_x u$")
        v_u_dx_label.scale(frame_scale * text_scale)
        v_u_dx_label.next_to(v_u_dx_point, RIGHT*(frame_scale * text_scale))
        v_u_dx_label.set_color(BLUE)
        v_u_dy_label = TexText("$\Delta_y u$")
        v_u_dy_label.scale(frame_scale * text_scale)
        v_u_dy_label.next_to(v_u_dy_point, LEFT*(frame_scale * text_scale))
        v_u_dy_label.set_color(ORANGE)
        v_u_dx_line = DashedLine(start=v_u_dx_point, end=dx_point, stroke_color=BLUE, stroke_width = arrow_stroke_width/3)
        v_u_dy_line = DashedLine(start=v_u_dy_point, end=dy_point, stroke_color=ORANGE, stroke_width = arrow_stroke_width/3)

        self.play(
            Write(v_u_dx),
            Write(v_u_dx_line),
            Write(v_u_dx_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(v_u_dy),
            Write(v_u_dy_line),
            Write(v_u_dy_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        v_v_dx_point = [base_point[0], dx_point[1], 0.]
        v_v_dy_point = [base_point[0], dy_point[1], 0.]
        v_v_dx = Arrow(start=base_point, end=v_v_dx_point, buff=0, stroke_color=BLUE, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_dy = Arrow(start=base_point, end=v_v_dy_point, buff=0, stroke_color=ORANGE, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_dx_label = TexText("$\Delta_x v$")
        v_v_dx_label.scale(frame_scale * text_scale)
        v_v_dx_label.next_to(v_v_dx_point, LEFT*(frame_scale * text_scale))
        v_v_dx_label.set_color(BLUE)
        v_v_dy_label = TexText("$\Delta_y v$")
        v_v_dy_label.scale(frame_scale * text_scale)
        v_v_dy_label.next_to(v_v_dy_point, LEFT*(frame_scale * text_scale))
        v_v_dy_label.set_color(ORANGE)
        v_v_dx_line = DashedLine(start=v_v_dx_point, end=dx_point, stroke_color=BLUE, stroke_width = arrow_stroke_width/3)
        v_v_dy_line = DashedLine(start=v_v_dy_point, end=dy_point, stroke_color=ORANGE, stroke_width = arrow_stroke_width/3)

        self.play(
            Write(v_v_dx),
            Write(v_v_dx_line),
            Write(v_v_dx_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(v_v_dy),
            Write(v_v_dy_line),
            Write(v_v_dy_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.wait(interval_time)