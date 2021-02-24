// edited from: https://github.com/mneumann/matplotlib-rs/blob/master/src/lib.rs
// Original author: Michael Neumann
// Original License: MIT License

use cpython::{Python, ToPyObject};
use cpython::ObjectProtocol;
//for call method
use cpython::{PyModule, PyTuple};

pub struct Env {
    gil: cpython::GILGuard,
}

impl Env {
    pub fn new() -> Env {
        Env { gil: Python::acquire_gil() }
    }
}

pub struct Plot<'p> {
    pub py: Python<'p>,
    pub plt: PyModule,
}

#[allow(dead_code)]
impl<'p> Plot<'p> {
    pub fn new<'a>(env: &'a Env) -> Plot<'a> {
        let py = env.gil.python();
        let plt = PyModule::import(py, "matplotlib.pyplot").unwrap();

        Plot { py: py, plt: plt }
    }

    pub fn interactive(&self) {
        let _ = self.plt.call(self.py, "ion", PyTuple::empty(self.py), None).unwrap();
    }

    pub fn show(&self) {
        let _ = self.plt.call(self.py, "show", PyTuple::empty(self.py), None).unwrap();
    }

    pub fn scatter<T: ToPyObject, U: ToPyObject>(&self, x: &[T], y: &[U]) {
        assert!(x.len() == y.len());
        let _ = self.plt.call(self.py, "scatter", (x, y), None).unwrap();
    }

    pub fn hist<T: ToPyObject>(&self, x: &[T]) {
        let _ = self.plt.call(self.py, "hist", (x, ), None).unwrap();
    }

    pub fn title(&self, title: &str) {
        let _ = self.plt.call(self.py, "title", (title, ), None).unwrap();
    }

    pub fn xlabel(&self, label: &str) {
        let _ = self.plt.call(self.py, "xlabel", (label, ), None).unwrap();
    }

    pub fn ylabel(&self, label: &str) {
        let _ = self.plt.call(self.py, "ylabel", (label, ), None).unwrap();
    }

    pub fn grid(&self, grid: bool) {
        let _ = self.plt.call(self.py, "grid", (grid, ), None).unwrap();
    }

    pub fn figure(&self, x: usize) {
        let _ = self.plt.call(self.py, "figure", (x, ), None).unwrap();
    }

    pub fn draw(&self) {
        let _ = self.plt.call(self.py, "draw", PyTuple::empty(self.py), None).unwrap();
    }

    /// Clear figure
    pub fn clf(&self) {
        let _ = self.plt.call(self.py, "clf", PyTuple::empty(self.py), None).unwrap();
    }
}

/// Convenience function for one-shot plots.
pub fn scatterplot<T: ToPyObject, U: ToPyObject>(x: &[T], y: &[U]) {
    let env = Env::new();
    let plot = Plot::new(&env);

    // draw the actual data
    plot.scatter(x, y);

    // display window
    plot.show();
}