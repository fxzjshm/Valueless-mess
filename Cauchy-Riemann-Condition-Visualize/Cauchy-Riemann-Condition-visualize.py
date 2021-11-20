from typing_extensions import runtime
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

dx_color = GREEN
dy_color = RED
u_v_dx_color = BLUE
u_v_dy_color = ORANGE

# for debugging sync
sync_point = Text("Syncing ......")
debug_sync = False

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
        debug_sync_dot(self)

        # dx, dy
        dx_point = c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = c_grid.coords_to_point(base_point_x, base_point_y + dy)
        dx_dot = Dot(dx_point, color=dx_color)
        dy_dot = Dot(dy_point, color=dy_color)
        
        self.play(
            Write(dx_dot),
            run_time=0.6*animation_time
        )
        self.wait(0.2*animation_time)
        self.wait(interval_time)

        self.play(
            Write(dy_dot),
            run_time=0.6*animation_time
        )
        self.wait(0.2*animation_time)
        self.wait(0.4*animation_time)
        self.wait(interval_time)

        ## sync point 2 - dx and dy drawn
        ## 2 t1 + 2 t2
        debug_sync_dot(self)

        # the other scene is being transformed, so just wait
        self.wait(4*animation_time)
        self.wait(interval_time)

        ## sync point 3 - transformation applied
        ## 4 t1 + t2
        debug_sync_dot(self)

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
        debug_sync_dot(self)

        # arrows and labels
        base_point = base_dot.get_center()
        dx_point = dx_dot.get_center()
        dy_point = dy_dot.get_center()
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dx_label = TexText("$\Delta x$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(dx_point, DOWN*(frame_scale * text_scale))
        v_dx_label.set_color(dx_color)
        v_dy_label = TexText("$\Delta y$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(dy_point, LEFT*(frame_scale * text_scale))
        v_dy_label.set_color(dy_color)

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
        debug_sync_dot(self)

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

        ## sync point 6 - moving dot
        # 4 t1 + 2 t2

        self.wait(4*animation_time + 4*interval_time)
        
        ## sync point 7 - analyze
        # 4 t1 + 4 t2
        debug_sync_dot(self)

        self.wait(3*animation_time + 10*interval_time)

        ## sync point 8 - explanation
        # 3 t1 + 10 t2
        debug_sync_dot(self)

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
        debug_sync_dot(self)

        # dx, dy
        dx_point = moving_c_grid.coords_to_point(base_point_x + dx, base_point_y)
        dy_point = moving_c_grid.coords_to_point(base_point_x, base_point_y + dy)
        dx_dot = SmallDot(dx_point, color=dx_color)
        dy_dot = SmallDot(dy_point, color=dy_color)

        self.play(
            Write(dx_dot),
            run_time=0.6*animation_time
        )
        self.wait(0.2*animation_time)
        self.wait(interval_time)

        self.play(
            Write(dy_dot),
            run_time=0.6*animation_time
        )
        self.wait(0.2*animation_time)
        self.wait(0.4*animation_time)
        self.wait(interval_time)

        ## sync point 2 - dx and dy drawn
        ## 2 t1 + 2 t2
        debug_sync_dot(self)

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
        debug_sync_dot(self)

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
        debug_sync_dot(self)

        # arrows and labels
        base_point = base_dot.get_center()
        dx_point = dx_dot.get_center()
        dy_point = dy_dot.get_center()
        v_dx = Arrow(start=base_point, end=dx_point, buff=0, stroke_color=dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dy = Arrow(start=base_point, end=dy_point, buff=0, stroke_color=dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_dx_label = TexText("$\Delta_x f$")
        v_dx_label.scale(frame_scale * text_scale)
        v_dx_label.next_to(dx_dot.get_center(), RIGHT*(frame_scale * text_scale * 2))
        v_dx_label.set_color(dx_color)
        v_dy_label = TexText("$\Delta_y f$")
        v_dy_label.scale(frame_scale * text_scale)
        v_dy_label.next_to(dy_dot.get_center(), LEFT*(frame_scale * text_scale * 2))
        v_dy_label.set_color(dy_color)

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
        debug_sync_dot(self)

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

        ## sync point 6 - moving dot
        # 4 t1 + 2 t2
        debug_sync_dot(self)

        # analyze u, v
        v_u_dx_point = [dx_point[0], base_point[1], 0.]
        v_u_dy_point = [dy_point[0], base_point[1], 0.]
        v_u_dx = Arrow(start=base_point, end=v_u_dx_point, buff=0, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_dy = Arrow(start=base_point, end=v_u_dy_point, buff=0, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_dx_label = TexText("$\Delta_x u$")
        v_u_dx_label.scale(frame_scale * text_scale)
        v_u_dx_label.next_to(v_u_dx_point, RIGHT*(frame_scale * text_scale))
        v_u_dx_label.set_color(u_v_dx_color)
        v_u_dy_label = TexText("$\Delta_y u$")
        v_u_dy_label.scale(frame_scale * text_scale)
        v_u_dy_label.next_to(v_u_dy_point, LEFT*(frame_scale * text_scale))
        v_u_dy_label.set_color(u_v_dy_color)
        v_u_dx_line = DashedLine(start=v_u_dx_point, end=dx_point, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width/3)
        v_u_dy_line = DashedLine(start=v_u_dy_point, end=dy_point, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width/3)

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
        v_v_dx = Arrow(start=base_point, end=v_v_dx_point, buff=0, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_dy = Arrow(start=base_point, end=v_v_dy_point, buff=0, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_dx_label = TexText("$\Delta_x v$")
        v_v_dx_label.scale(frame_scale * text_scale)
        v_v_dx_label.next_to(v_v_dx_point, LEFT*(frame_scale * text_scale))
        v_v_dx_label.set_color(u_v_dx_color)
        v_v_dy_label = TexText("$\Delta_y v$")
        v_v_dy_label.scale(frame_scale * text_scale)
        v_v_dy_label.next_to(v_v_dy_point, LEFT*(frame_scale * text_scale))
        v_v_dy_label.set_color(u_v_dy_color)
        v_v_dx_line = DashedLine(start=v_v_dx_point, end=dx_point, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width/3)
        v_v_dy_line = DashedLine(start=v_v_dy_point, end=dy_point, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width/3)

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

        ## sync point 7 - analyze
        # 4 t1 + 4 t2
        debug_sync_dot(self)

        self.wait(3*animation_time + 10*interval_time)

        ## sync point 8 - explanation
        # 3 t1 + 10 t2
        debug_sync_dot(self)

#########################################################################################

class CR_Visualize_text(Scene):
    def construct(self):
        text_scale = 1

        self.wait(2*animation_time)
        self.wait(interval_time)

        # base point
        text_base_point = Text("在复平面上取一点")
        text_base_point.scale(text_scale)
        text_base_point.to_corner(UP)
        self.play(
            Write(text_base_point, run_time=0.3*animation_time),
        )
        self.wait(0.7*animation_time)
        self.play(
            FadeOut(text_base_point, run_time=interval_time),
        )

        ## sync point 1 - write coordinate
        ## 3 t1 + 2 t2 used
        debug_sync_dot(self)

        # dx, dy
        text_dx_dy_1 = Text("并设在它的邻域内有向实轴方向的微小移动 ")
        text_dx = TexText("$\Delta x (\\rightarrow 0)$", color=dx_color)
        text_dx_dy_2 = Text(" 与向虚轴方向的微小移动 ")
        text_dy = TexText("$\Delta y (\\rightarrow 0)$", color=dy_color)
        group_dx_dy = VGroup(VGroup(text_dx_dy_1, text_dx).arrange(), VGroup(text_dx_dy_2, text_dy).arrange())
        group_dx_dy.arrange(DOWN, aligned_edge=RIGHT)
        group_dx_dy.scale(text_scale)
        group_dx_dy.to_corner(UP)

        # for unknown reason here we need to be faster
        self.play(
            Write(text_dx_dy_1, run_time=0.4*animation_time),
        )
        self.play(
            Write(text_dx, run_time=0.2*animation_time),
        )
        
        self.play(
            Write(text_dx_dy_2, run_time=0.4*animation_time),
        )
        self.play(
            Write(text_dy, run_time=0.2*animation_time),
        )
        self.wait(0.4*animation_time)
        self.wait(interval_time)
        self.play(
            FadeOut(text_dx_dy_1),
            FadeOut(text_dx),
            FadeOut(text_dx_dy_2),
            FadeOut(text_dy),
            runtime=0.8*interval_time
        )

        ## sync point 2 - dx and dy drawn
        ## 2 t1 + 2 t2
        debug_sync_dot(self)

        text_transformation = TexText("考虑一个解析函数 $f(z)$，变换前后如上")
        text_transformation.to_corner(UP)
        self.play(
            Write(text_transformation, run_time=1.5*animation_time),
        )
        self.wait(2.5*animation_time)
        self.play(
            FadeOut(text_transformation),
            runtime=interval_time
        )

        ## sync point 3 - transformation applied
        ## 4 t1 + t2
        debug_sync_dot(self)

        text_zoom = Text("在这一点的邻域")
        text_zoom.to_corner(UP)
        self.play(
            Write(text_zoom, run_time=animation_time),
        )
        self.wait(animation_time)
        self.wait(interval_time)
        self.play(
            FadeOut(text_zoom),
            runtime=interval_time
        )

        ## sync point 4 - camera shifted and zoomed
        # 2 t1 + 2 t2
        debug_sync_dot(self)

        text_and_1 = TexText(" 和 ")
        text_df_1 = TexText(" 两个位移分别引起 $f$ 的两种变化 ")
        text_dx_f = TexText("$\Delta_x f$", color=dx_color)
        text_and_2 = TexText(" 和 ")
        text_dy_f = TexText("$\Delta_y f$", color=dy_color)
        group_df = VGroup(text_dx, text_and_1, text_dy, text_df_1, text_dx_f, text_and_2, text_dy_f)
        group_df.arrange(RIGHT)
        group_df.scale(0.8)
        group_df.to_corner(UP)
        self.play(
            Write(group_df, run_time=animation_time),
        )
        self.wait(interval_time)
        self.wait(animation_time)
        self.wait(interval_time)

        ## sync point 5 - vectors and labels
        # 2 t1 + 2 t2
        debug_sync_dot(self)

        self.wait(4*animation_time)
        self.wait(interval_time)
        self.play(
            FadeOut(group_df),
            runtime=interval_time
        )

        ## sync point 6 - moving point
        # 4 t1 + 2 t2
        debug_sync_dot(self)

        text_analyze = TexText("分解如上")
        group_analyze = VGroup(text_dx_f, text_and_2, text_dy_f, text_analyze)
        group_analyze.arrange(RIGHT)
        group_analyze.to_corner(UP)
        self.play(
            Write(group_analyze, run_time=animation_time),
        )
        self.wait(2*interval_time)
        self.play(
            FadeOut(group_analyze),
            runtime=interval_time
        )
        # speed up a bit here
        self.wait(3*animation_time + 0*interval_time)
        
        ## sync point 7 - analyze
        # 4 t1 + 4 t2
        debug_sync_dot(self)

        # explanation
        text_proof_1 = Text("由复变函数导数的几何性质，")
        text_proof_2 = Text(" 的模长应当相同，")
        text_proof_3 = Text("夹角与 ")
        text_proof_4 = Text(" 的夹角相同，即逆时针转过 90°")
        group_proof_1 = VGroup(text_proof_1, text_dx_f, text_and_1, text_dy_f, text_proof_2).arrange(RIGHT)
        group_proof_2 = VGroup(text_proof_3, text_dx, text_and_2, text_dy, text_proof_4).arrange(RIGHT)
        group_proof = VGroup(group_proof_1, group_proof_2).arrange(DOWN)

        text_CR_1 = Tex("\\therefore", "\Delta_x u", "=", "\Delta_y v", ", ", "\Delta_y u", "=", "-", "\Delta_x v")
        text_CR_1.set_color_by_tex_to_color_map({
            "\Delta_x u": u_v_dx_color,
            "\Delta_y u": u_v_dy_color,
            "\Delta_x v": u_v_dx_color,
            "\Delta_y v": u_v_dy_color
        })

        text_CR_2 = Tex("\\therefore", "\partial_x u", "=", "\partial_y v", ", ", "\partial_y u", "=", "-", "\partial_x v")
        text_CR_2.set_color_by_tex_to_color_map({
            "\partial_x u": u_v_dx_color,
            "\partial_y u": u_v_dy_color,
            "\partial_x v": u_v_dx_color,
            "\partial_y v": u_v_dy_color
        })

        group_final = VGroup(group_proof)
        group_final.arrange(DOWN)
        group_final.to_corner(UP)

        text_CR_1.to_corner(UP)
        text_CR_2.to_corner(UP)

        self.play(
            Write(group_proof, run_time=animation_time),
        )
        self.wait(2*interval_time)

        self.play(
            FadeOut(group_proof, run_time=animation_time),
        )
        self.wait(interval_time)

        self.play(
            Write(text_CR_1, run_time=animation_time),
        )
        self.wait(2*interval_time)


        self.play(
            TransformMatchingTex(
                text_CR_1, text_CR_2,
                key_map={
                    "\Delta_x u": "\partial_x u",
                    "\Delta_y u": "\partial_y u",
                    "\Delta_x v": "\partial_x v",
                    "\Delta_y v": "\partial_y v"
                }
            ),
            run_time=animation_time
        )
        self.wait(5*interval_time)

        ## sync point 8 - explanation
        # 3 t1 + 10 t2
        debug_sync_dot(self)

def debug_sync_dot(scene):
    if debug_sync:
        sync_point.arrange()
        scene.play(
            Write(sync_point),
            run_time=animation_time
        )
        scene.play(
            FadeOut(sync_point),
            run_time=interval_time
        )