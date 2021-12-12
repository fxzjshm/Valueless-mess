# Cauchy-Riemann condition visualize
#
# Copyright (C) 2021 fxzjshm
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# This project uses documention at https://docs.manim.org.cn/
# many thanks to them

# exported video is copyrighted

# metadata modified from the template from https://stackoverflow.com/questions/1523427/what-is-the-common-header-format-of-python-files by Esteban Küber
__author__ = "fxzjshm"
__copyright__ = "Copyright (C) 2021 fxzjshm"
__license__ = "GPL"
__version__ = "v3 or later"
__email__ = "fxzjshm@163.com"

from manimlib import *
from numpy import cos, sin

# global parameters
c_grid_len = FRAME_WIDTH # /3
c_grid_range = [-10, 10, 1]
buff = 0 # FRAME_WIDTH/10
animation_time = 1
interval_time = 0.8
arrow_max_tip_length_to_length_ratio = 0.25
arrow_stroke_width = 2

base_point_x = 1.
base_point_y = 2.
dx = 0.2
dy = 0.2
theta_1 = 0.233
theta_2 = 2.333

dx_color = GREEN
dy_color = RED
u_v_dx_color = TEAL
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
        dots = VGroup(base_dot, dx_dot, dy_dot)
        base_elements = VGroup(c_grid, dots)
        self.play(
            base_elements.animate.shift(-dots.get_center_of_mass()),
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

        # explanation
        v_rotate = v_dx.copy().set_color(WHITE)
        rotate_angle = v_dy.get_angle() - v_dx.get_angle()

        self.wait(animation_time)
        self.wait(2*interval_time)
        self.play(FadeIn(v_rotate), run_time=interval_time)
        self.play(Rotate(v_rotate, angle=rotate_angle, about_point=base_dot.get_center()), run_time=2*interval_time)
        self.play(FadeOut(v_rotate), run_time=interval_time)
        self.wait(2*interval_time)

        self.wait(3*animation_time + 8*interval_time)

        ## sync point 8 - explanation - 1
        # 4 t1 + 16 t2
        debug_sync_dot(self)

        self.wait(5*animation_time + 13*interval_time)

        self.play(
            FadeOut(v_dx),
            FadeOut(v_dy),
            FadeOut(dx_dot),
            FadeOut(dy_dot),
            FadeOut(v_dx_label),
            FadeOut(v_dy_label),
            run_time=interval_time
        )
        
        ## sync point 8.1 - explanation - 2 - Jacobian matrix
        # 5 t1 + 14 t2
        debug_sync_dot(self)

        # port to any two vectors
        v1_point = base_point + (dx_point - base_point) * cos(theta_1) + (dy_point - base_point) * sin(theta_1)
        v2_point = base_point + (dx_point - base_point) * cos(theta_2) + (dy_point - base_point) * sin(theta_2)
        v_v1 = Arrow(start=base_point, end=v1_point, buff=0, stroke_color=dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v2 = Arrow(start=base_point, end=v2_point, buff=0, stroke_color=dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v1_label = TexText("$z_1$")
        v_v1_label.scale(frame_scale * text_scale)
        v_v1_label.next_to(v1_point, RIGHT*(frame_scale * text_scale))
        v_v1_label.set_color(dx_color)
        v_v2_label = TexText("$z_2$")
        v_v2_label.scale(frame_scale * text_scale)
        v_v2_label.next_to(v2_point, LEFT*(frame_scale * text_scale))
        v_v2_label.set_color(dy_color)

        self.play(
            Write(v_v1),
            Write(v_v1_label),
            run_time=animation_time
        )
        self.wait(interval_time)
        self.play(
            Write(v_v2),
            Write(v_v2_label),
            run_time=animation_time
        )
        self.wait(3*interval_time)

        ## sync point 9 - v1 and v2 drawn
        # 2 t1 + 4 t2
        debug_sync_dot(self)

        '''
        self.wait(4*animation_time + 4*interval_time)

        ## sync point 10 - analyze - 2
        # 4 t1 + 4 t2
        debug_sync_dot(self)
        '''

        v_rotate = v_v1.copy().set_color(WHITE)
        rotate_angle = (v_v2.get_angle() - v_v1.get_angle())

        #self.wait(animation_time)
        #self.wait(2*interval_time)
        self.play(FadeIn(v_rotate), run_time=animation_time)
        self.play(Rotate(v_rotate, angle=rotate_angle, about_point=base_dot.get_center()), run_time=2*animation_time)
        self.play(FadeOut(v_rotate), run_time=animation_time)
        self.wait(2*interval_time)

        self.wait(1*animation_time + 8*interval_time)

        ## sync point 11 - explanation - 3
        # 2 t1 + 16 t2
        debug_sync_dot(self)

        self.play(
            FadeOut(v_v1),
            FadeOut(v_v2),
            FadeOut(v_v1_label),
            FadeOut(v_v2_label),
            run_time=interval_time
        )

        self.play(
            FadeOut(c_grid),
            FadeOut(base_dot),
            run_time=interval_time
        )

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
        dots = VGroup(base_dot, dx_dot, dy_dot)
        base_elements = VGroup(moving_c_grid, dots)
        
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
            base_elements.animate.shift(-dots.get_center_of_mass()),
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

        # explanation
        v_rotate = v_dx.copy().set_color(WHITE)
        rotate_angle = v_dy.get_angle() - v_dx.get_angle()

        self.wait(animation_time)
        self.wait(2*interval_time)
        self.play(FadeIn(v_rotate), run_time=interval_time)
        self.play(Rotate(v_rotate, angle=rotate_angle, about_point=base_dot.get_center()), run_time=2*interval_time)
        self.play(FadeOut(v_rotate), run_time=interval_time)
        self.wait(2*interval_time)

        self.wait(3*animation_time + 8*interval_time)

        ## sync point 8 - explanation - 1
        # 4 t1 + 16 t2
        debug_sync_dot(self)

        self.wait(5*animation_time + 13*interval_time)

        self.play(
            FadeOut(v_dx),
            FadeOut(v_dy),
            FadeOut(dx_dot),
            FadeOut(dy_dot),
            FadeOut(v_dx_label),
            FadeOut(v_dy_label),

            FadeOut(v_u_dx),
            FadeOut(v_u_dx_line),
            FadeOut(v_u_dx_label),

            FadeOut(v_u_dy),
            FadeOut(v_u_dy_line),
            FadeOut(v_u_dy_label),

            FadeOut(v_v_dx),
            FadeOut(v_v_dx_line),
            FadeOut(v_v_dx_label),

            FadeOut(v_v_dy),
            FadeOut(v_v_dy_line),
            FadeOut(v_v_dy_label),
            run_time=interval_time
        )
        
        ## sync point 8.1 - explanation - 2 - Jacobian matrix
        # 5 t1 + 14 t2
        debug_sync_dot(self)

        # port to any two vectors
        v1_point = base_point + (dx_point - base_point) * cos(theta_1) + (dy_point - base_point) * sin(theta_1)
        v2_point = base_point + (dx_point - base_point) * cos(theta_2) + (dy_point - base_point) * sin(theta_2)
        v_v1 = Arrow(start=base_point, end=v1_point, buff=0, stroke_color=dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v2 = Arrow(start=base_point, end=v2_point, buff=0, stroke_color=dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v1_label = TexText("$\Delta_{z_1} f$")
        v_v1_label.scale(frame_scale * text_scale)
        v_v1_label.next_to(v1_point, LEFT*(frame_scale * text_scale))
        v_v1_label.set_color(dx_color)
        v_v2_label = TexText("$\Delta_{z_2} f$")
        v_v2_label.scale(frame_scale * text_scale)
        v_v2_label.next_to(v2_point, LEFT*(frame_scale * text_scale))
        v_v2_label.set_color(dy_color)

        self.play(
            Write(v_v1),
            Write(v_v1_label),
            run_time=animation_time
        )
        self.wait(interval_time)
        self.play(
            Write(v_v2),
            Write(v_v2_label),
            run_time=animation_time
        )
        self.wait(3*interval_time)

        ## sync point 9 - v1 and v2 drawn
        # 2 t1 + 4 t2
        debug_sync_dot(self)

        '''
        v_u_v1_point = [v1_point[0], base_point[1], 0.]
        v_u_v2_point = [v2_point[0], base_point[1], 0.]
        v_u_v1 = Arrow(start=base_point, end=v_u_v1_point, buff=0, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_v2 = Arrow(start=base_point, end=v_u_v2_point, buff=0, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_u_v1_label = TexText("$\Delta_{z_1} u$")
        v_u_v1_label.scale(frame_scale * text_scale)
        v_u_v1_label.next_to(v_u_v1_point, UL*(frame_scale * text_scale))
        v_u_v1_label.set_color(u_v_dx_color)
        v_u_v2_label = TexText("$\Delta_{z_2} u$")
        v_u_v2_label.scale(frame_scale * text_scale)
        v_u_v2_label.next_to(v_u_v2_point, LEFT*(frame_scale * text_scale))
        v_u_v2_label.set_color(u_v_dy_color)
        v_u_v1_line = DashedLine(start=v_u_v1_point, end=v1_point, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width/3)
        v_u_v2_line = DashedLine(start=v_u_v2_point, end=v2_point, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width/3)

        self.play(
            Write(v_u_v1),
            Write(v_u_v1_line),
            Write(v_u_v1_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(v_u_v2),
            Write(v_u_v2_line),
            Write(v_u_v2_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        v_v_v1_point = [base_point[0], v1_point[1], 0.]
        v_v_v2_point = [base_point[0], v2_point[1], 0.]
        v_v_v1 = Arrow(start=base_point, end=v_v_v1_point, buff=0, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_v2 = Arrow(start=base_point, end=v_v_v2_point, buff=0, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width, max_tip_length_to_length_ratio=arrow_max_tip_length_to_length_ratio)
        v_v_v1_label = TexText("$\Delta_{z_1} v$")
        v_v_v1_label.scale(frame_scale * text_scale)
        v_v_v1_label.next_to(v_v_v1_point, RIGHT*(frame_scale * text_scale))
        v_v_v1_label.set_color(u_v_dx_color)
        v_v_v2_label = TexText("$\Delta_{z_2} v$")
        v_v_v2_label.scale(frame_scale * text_scale)
        v_v_v2_label.next_to(v_v_v2_point, DOWN*(frame_scale * text_scale))
        v_v_v2_label.set_color(u_v_dy_color)
        v_v_v1_line = DashedLine(start=v_v_v1_point, end=v1_point, stroke_color=u_v_dx_color, stroke_width = arrow_stroke_width/3)
        v_v_v2_line = DashedLine(start=v_v_v2_point, end=v2_point, stroke_color=u_v_dy_color, stroke_width = arrow_stroke_width/3)

        self.play(
            Write(v_v_v1),
            Write(v_v_v1_line),
            Write(v_v_v1_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        self.play(
            Write(v_v_v2),
            Write(v_v_v2_line),
            Write(v_v_v2_label),
            run_time=animation_time
        )
        self.wait(interval_time)

        ## sync point 10 - analyze - 2
        # 4 t1 + 4 t2
        debug_sync_dot(self)
        '''

        v_rotate = v_v1.copy().set_color(WHITE)
        rotate_angle = (v_v2.get_angle() - v_v1.get_angle()) + 2*PI

        #self.wait(animation_time)
        #self.wait(2*interval_time)
        self.play(FadeIn(v_rotate), run_time=animation_time)
        self.play(Rotate(v_rotate, angle=rotate_angle, about_point=base_dot.get_center()), run_time=2*animation_time)
        self.play(FadeOut(v_rotate), run_time=animation_time)
        self.wait(2*interval_time)

        self.wait(1*animation_time + 8*interval_time)

        ## sync point 11 - explanation - 3
        # 5 t1 + 10 t2
        debug_sync_dot(self)

        self.play(
            FadeOut(v_v1),
            FadeOut(v_v2),
            FadeOut(v_v1_label),
            FadeOut(v_v2_label),

            
            #FadeOut(v_u_v1),
            #FadeOut(v_u_v1_line),
            #FadeOut(v_u_v1_label),

            #FadeOut(v_u_v2),
            #FadeOut(v_u_v2_line),
            #FadeOut(v_u_v2_label),

            #FadeOut(v_v_v1),
            #FadeOut(v_v_v1_line),
            #FadeOut(v_v_v1_label),

            #FadeOut(v_v_v2),
            #FadeOut(v_v_v2_line),
            #FadeOut(v_v_v2_label),
            

            run_time=interval_time
        )

        self.play(
            FadeOut(moving_c_grid),
            FadeOut(base_dot),
            run_time=interval_time
        )

#########################################################################################

class CR_Visualize_text(Scene):
    def construct(self):
        text_scale = 1

        self.wait(2*animation_time)
        #self.wait(interval_time)

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
        self.wait(3*animation_time + 2*interval_time)
        self.play(
            FadeOut(group_analyze),
            runtime=interval_time
        )
        self.wait(interval_time)
        
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
        self.wait(8*interval_time)

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
        self.wait(3*interval_time)
        self.play(
            FadeOut(text_CR_2, run_time=interval_time),
        )
        self.wait(interval_time)

        ## sync point 8 - explanation - 1
        # 4 t1 + 16 t2
        debug_sync_dot(self)

        # v0.0.3: add Jacobian matrix
        text_jacobi_1 = Text("或可以考虑切空间之间的线性变换，即考虑 Jacobian 矩阵")
        text_jacobi_matrix_1 = Tex(
            R'''
            
            J = 
            \begin{bmatrix}  
              {\partial u \over \partial x} & {\partial u \over \partial y} \\  
              {\partial v \over \partial x} & {\partial v \over \partial y}
            \end{bmatrix}
            
            '''
        )
        text_jacobi_matrix_2 = Tex(
            R'''
            
            = k
            \begin{bmatrix}  
              \cos \theta & -\sin \theta \\
              \sin \theta & \cos \theta
            \end{bmatrix}
            
            '''
        )
        text_jacobi_2 = Text("由于导数必须能写成复数，即伸缩与旋转，故有")
        text_jacobi_2.to_corner(UP)
        text_jacobi_3 = Tex(R"\Rightarrow {\partial u \over \partial x} = {\partial v \over \partial y}, ~ {\partial u \over \partial y} = - {\partial v \over \partial x}")
        group_jacobi_matrix = VGroup(text_jacobi_matrix_1, text_jacobi_matrix_2, text_jacobi_3).arrange(RIGHT)
        group_jacobi = VGroup(text_jacobi_1, group_jacobi_matrix)
        group_jacobi.arrange(DOWN).to_corner(UP)
        
        self.play(
            Write(text_jacobi_1),
            run_time=animation_time
        )
        self.play(
            Write(text_jacobi_matrix_1),
            run_time=animation_time
        )
        self.wait(2*interval_time)
        self.play(
            Transform(text_jacobi_1, text_jacobi_2),
            run_time=animation_time
        )
        self.wait(interval_time)
        self.play(
            Write(text_jacobi_matrix_2),
            run_time=animation_time
        )
        self.wait(3*interval_time)
        self.play(
            Write(text_jacobi_3),
            run_time=animation_time
        )
        self.wait(6*interval_time)
        self.play(
            FadeOut(group_jacobi_matrix),
            FadeOut(text_jacobi_1),
            #FadeOut(text_jacobi_2),
            run_time=interval_time
        )
        self.wait(2*interval_time)
        ## sync point 8.1 - explanation - 2 - Jacobian matrix
        # 5 t1 + 14 t2
        debug_sync_dot(self)

        # v0.0.2: add port
        text_port = TexText("推广到任意 ")
        text_z_1 = TexText("$z_1$", color=dx_color)
        text_comma = TexText(" , ")
        text_z_2 = TexText("$z_2$", color=dy_color)
        group_port = VGroup(text_port, text_z_1, text_comma, text_z_2)
        group_port.arrange(RIGHT)
        group_port.to_corner(UP)

        self.play(
            Write(group_port, run_time=animation_time),
        )
        self.wait(3*interval_time)

        self.play(
            FadeOut(group_port, run_time=animation_time),
        )
        self.wait(interval_time)

        ## sync point 9 - v1 and v2 drawn
        # 2 t1 + 4 t2
        debug_sync_dot(self)

        '''
        self.wait(4*animation_time + 4*interval_time)

        ## sync point 10 - analyze - 2
        # 4 t1 + 4 t2
        debug_sync_dot(self)
        '''

        #self.wait(1*animation_time + 2*interval_time)
        self.wait(4*animation_time + 2*interval_time)
        
        text_port_conclusion_1 = Text("由保角性可以得到 ")
        text_port_conclusion_2 = TexText(
            R'''
            $$
            \begin{bmatrix}  
              {\partial u \over \partial z_2} \\  
              {\partial v \over \partial z_2}
            \end{bmatrix}
            =
            \begin{bmatrix}  
              \cos \theta & -\sin \theta \\
              \sin \theta & \cos \theta
            \end{bmatrix}
            \begin{bmatrix}  
              {\partial u \over \partial z_1} \\  
              {\partial v \over \partial z_1}
            \end{bmatrix}
            $$
            '''
        )
        group_port_conclusion = VGroup(text_port_conclusion_1, text_port_conclusion_2).arrange(RIGHT)
        group_port_conclusion.to_corner(UP)

        self.play(
            Write(group_port_conclusion, run_time=animation_time),
        )
        self.wait(8*interval_time)

        ## sync point 11 - explanation - 3
        # 2 t1 + 16 t2
        debug_sync_dot(self)

        self.play(
            FadeOut(group_port_conclusion),
            run_time=interval_time
        )

        self.wait(interval_time)

#########################################################################################

class CR_Visualize_startup(Scene):
    def construct(self):
        title = TexText("Cauchy-Riemann 条件的直观理解")
        info = Text("作者: fxzjshm")

        title.scale(1.3)
        title.center()
        info.scale(0.5)
        info.to_corner(RIGHT + DOWN)

        self.play(
            Write(title, run_time=animation_time),
        )
        self.wait(interval_time)
        self.play(
            Write(info, run_time=0.5*animation_time),
        )
        self.wait(2*interval_time)
        self.play(
            FadeOut(title),
            FadeOut(info),
            run_time=animation_time
        )
        self.wait(interval_time)

class CR_Visualize_ending(Scene):
    def construct(self):
        notice = TexText(
            """
            \\begin{flushleft}
            \\begin{small}
            作者: fxzjshm ~\\\\
            视频画面部分： Copyright (C) 2021 fxzjshm ~\\\\
            ~\\\\
            此视频仅限 Bilibili 发布。 ~\\\\
            需获得具有作者 GPG 签名的授权文件方可转载，原因见下。 ~\\\\
            ~\\\\
            ------ ~\\\\
            ~\\\\
            敬告盗视频者（包括自动盗视频程序的操纵者）： ~\\\\
            未经授权，不得以任何形式通过任何途径将此视频的任何部分转载至任何其他平台， ~\\\\
            包括但不限于 抖音、快手、火山小视频、西瓜视频、优酷、爱奇艺、百家号、好看视频、 ~\\\\
            搜狐视频、腾讯视频、腾讯微视、腾讯企鹅号、微信视频号、梨视频、CSDN 等； ~\\\\
            对于任何侵权行为，作者保留追究法律责任的权利。 ~\\\\
            ~\\\\
            ------ ~\\\\
            ~\\\\
            此视频画面部分的源代码以 GNU 通用公共许可证第 3 版或其后续版本授权。 ~\\\\
            此视频使用 Grant Sanderson “3Blue1Brown” 开发的 manim 引擎， ~\\\\
            制作中参考了 manim-kindergarten 团队编写的 manim 教程，非常感谢。 ~\\\\
            ~\\\\
            BGM: Foxtail-Grass Studio 雲流れ
            \\end{small}
            \\end{flushleft}
            """,
            font_size=18,
            #font="Noto Sans CJK SC",
            #stroke_width=0,
            #t2c={'Blue':BLUE, 'Brown':GREY_BROWN},
        )

        # notice.scale(0.3)
        notice.center()

        self.play(
            FadeIn(notice, run_time=0.5*animation_time),
        )
        self.wait(2*interval_time)
        self.play(
            FadeOut(notice),
            run_time=0.5*animation_time
        )
        #self.wait(2*interval_time)

#########################################################################################

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
