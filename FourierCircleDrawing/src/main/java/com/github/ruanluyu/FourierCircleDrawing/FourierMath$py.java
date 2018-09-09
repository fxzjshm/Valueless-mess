package com.github.ruanluyu.FourierCircleDrawing;

import org.python.compiler.APIVersion;
import org.python.compiler.Filename;
import org.python.compiler.MTime;
import org.python.core.CodeBootstrap;
import org.python.core.CodeLoader;
import org.python.core.ContextGuard;
import org.python.core.ContextManager;
import org.python.core.Py;
import org.python.core.PyCode;
import org.python.core.PyComplex;
import org.python.core.PyException;
import org.python.core.PyFrame;
import org.python.core.PyFunction;
import org.python.core.PyFunctionTable;
import org.python.core.PyInteger;
import org.python.core.PyList;
import org.python.core.PyObject;
import org.python.core.PyRunnable;
import org.python.core.PyRunnableBootstrap;
import org.python.core.PyString;
import org.python.core.PyTuple;
import org.python.core.ThreadState;
import org.python.core.imp;

@APIVersion(36)
@MTime(1535606033211L)
@Filename("D:\\workspace\\FourierCircleDrawing\\FourierMath\\FourierMath.py")
public class FourierMath$py extends PyFunctionTable implements PyRunnable {

    static FourierMath$py self;
    static PyCode f$0;
    static PyCode bezier$1;
    static PyCode linear$2;
    static PyCode prSolve$3;
    static PyCode numSolve$4;
    static PyCode cpToList$5;
    static PyCode initParam$6;
    static PyCode mainCalculation$7;

    public PyObject f$0(PyFrame var1, ThreadState var2) {
        var1.f_exits = new PyObject[2];
        var1.setline(3);
        String[] var3 = new String[] { "division" };
        PyObject[] var12 = imp.importFrom("__future__", var3, var1, -1);
        PyObject var4 = var12[0];
        var1.setlocal("division", var4);
        var4 = null;
        var1.setline(5);
        PyObject var13 = imp.importOne("math", var1, -1);
        var1.setlocal("math", var13);
        var3 = null;
        var1.setline(6);
        var13 = imp.importOne("cmath", var1, -1);
        var1.setlocal("cmath", var13);
        var3 = null;
        var1.setline(7);
        var13 = imp.importOne("re", var1, -1);
        var1.setlocal("re", var13);
        var3 = null;
        var1.setline(8);
        var13 = imp.importOne("time", var1, -1);
        var1.setlocal("time", var13);
        var3 = null;
        var1.setline(9);
        var13 = imp.importOne("multiprocessing", var1, -1);
        var1.setlocal("multiprocessing", var13);
        var3 = null;
        var1.setline(11);
        var12 = Py.EmptyObjects;
        PyFunction var15 = new PyFunction(var1.f_globals, var12, bezier$1, (PyObject) null);
        var1.setlocal("bezier", var15);
        var3 = null;
        var1.setline(14);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, linear$2, (PyObject) null);
        var1.setlocal("linear", var15);
        var3 = null;
        var1.setline(17);
        var13 = Py.newInteger(1)._truediv(var1.getname("math").__getattr__("pi")._mul(Py.newInteger(2)));
        var1.setlocal("oneOver2PI", var13);
        var3 = null;
        var1.setline(19);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, prSolve$3, (PyObject) null);
        var1.setlocal("prSolve", var15);
        var3 = null;
        var1.setline(29);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, numSolve$4, (PyObject) null);
        var1.setlocal("numSolve", var15);
        var3 = null;
        var1.setline(33);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, cpToList$5, (PyObject) null);
        var1.setlocal("cpToList", var15);
        var3 = null;
        var1.setline(35);
        PyInteger var21 = Py.newInteger(0);
        var1.setlocal("start", var21);
        var3 = null;
        var1.setline(36);
        var21 = Py.newInteger(1000);
        var1.setlocal("end", var21);
        var3 = null;
        var1.setline(37);
        var13 = var1.getname("end")._sub(var1.getname("start"))._add(Py.newInteger(1));
        var1.setlocal("prjNum", var13);
        var3 = null;
        var1.setline(38);
        var13 = var1.getname("None");
        var1.setlocal("prjCur", var13);
        var3 = null;
        var1.setline(39);
        PyList var22 = new PyList(Py.EmptyObjects);
        var1.setlocal("points", var22);
        var3 = null;
        var1.setline(40);
        var22 = new PyList(Py.EmptyObjects);
        var1.setlocal("out", var22);
        var3 = null;
        var1.setline(41);
        var22 = new PyList(new PyObject[] { Py.newInteger(500), Py.newInteger(500) });
        var1.setlocal("center", var22);
        var3 = null;
        var1.setline(42);
        var22 = new PyList(Py.EmptyObjects);
        var1.setlocal("curWeight", var22);
        var3 = null;
        var1.setline(43);
        var22 = new PyList(Py.EmptyObjects);
        var1.setlocal("trDatas", var22);
        var3 = null;
        var1.setline(44);
        var13 = var1.getname("None");
        var1.setlocal("sharedPoints", var13);
        var3 = null;
        var1.setline(46);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, initParam$6, (PyObject) null);
        var1.setlocal("initParam", var15);
        var3 = null;
        var1.setline(52);
        var12 = Py.EmptyObjects;
        var15 = new PyFunction(var1.f_globals, var12, mainCalculation$7, (PyObject) null);
        var1.setlocal("mainCalculation", var15);
        var3 = null;
        var1.setline(68);
        var13 = var1.getname("__name__");
        PyObject var10000 = var13._eq(PyString.fromInterned("__main__"));
        var3 = null;
        if (var10000.__nonzero__()) {
            ContextManager var23;
            var4 = (var23 = ContextGuard.getManager(var1.getname("open").__call__(var2,
                    PyString.fromInterned("rawvertexes.txt"), PyString.fromInterned("r")))).__enter__(var2);

            PyObject var5;
            PyObject var7;
            PyObject var8;
            PyObject var14;
            label188: {
                try {
                    var1.setlocal("f", var4);
                    var1.setline(70);
                    var4 = var1.getname("f").__getattr__("readlines").__call__(var2);
                    var1.setlocal("rawdata", var4);
                    var4 = null;
                    var1.setline(71);
                    var4 = var1.getname("re").__getattr__("sub").__call__(var2, PyString.fromInterned("\\s"),
                            PyString.fromInterned(""),
                            PyString.fromInterned("").__getattr__("join").__call__(var2, var1.getname("rawdata")));
                    var1.setlocal("curve", var4);
                    var4 = null;
                    var1.setline(72);
                    var4 = var1.getname("re").__getattr__("findall").__call__(var2,
                            PyString.fromInterned("\\w[\\d\\,\\-\\.]+"), var1.getname("curve"));
                    var1.setlocal("cells", var4);
                    var4 = null;
                    var1.setline(73);
                    var4 = var1.getname("cells").__iter__();

                    label182: while (true) {
                        var1.setline(73);
                        var5 = var4.__iternext__();
                        if (var5 == null) {
                            var1.setline(94);
                            Py.println(PyString.fromInterned("Vertexes data have been read."));
                            break;
                        }

                        var1.setlocal("cell", var5);
                        var1.setline(74);
                        PyList var6 = new PyList(Py.EmptyObjects);
                        var1.setlocal("trcdata", var6);
                        var6 = null;
                        var1.setline(75);
                        var14 = var1.getname("re").__getattr__("sub").__call__(var2, PyString.fromInterned("-"),
                                PyString.fromInterned(",-"), var1.getname("cell"));
                        var1.setlocal("formatString", var14);
                        var6 = null;
                        var1.setline(76);
                        var1.getname("trcdata").__getattr__("append").__call__(var2,
                                var1.getname("re").__getattr__("match")
                                .__call__(var2, PyString.fromInterned("[A-Za-z]"), var1.getname("formatString"))
                                .__getattr__("group").__call__(var2, Py.newInteger(0)));
                        var1.setline(77);
                        var14 = var1.getname("re").__getattr__("sub")
                                .__call__(var2, PyString.fromInterned("[A-Za-z]\\,?"), PyString.fromInterned(""),
                                        var1.getname("formatString"))
                                .__getattr__("split").__call__(var2, PyString.fromInterned(","));
                        var1.setlocal("rawvers", var14);
                        var6 = null;
                        var1.setline(78);
                        var14 = var1.getname("range")
                                .__call__(var2, var1.getname("len").__call__(var2, var1.getname("rawvers"))).__iter__();

                        while (true) {
                            var1.setline(78);
                            var7 = var14.__iternext__();
                            if (var7 == null) {
                                var1.setline(80);
                                var6 = new PyList(Py.EmptyObjects);
                                var1.setlocal("vergroup", var6);
                                var6 = null;
                                var1.setline(81);
                                var6 = new PyList(Py.EmptyObjects);
                                var1.setlocal("vercurgrp", var6);
                                var6 = null;
                                var1.setline(82);
                                var14 = var1.getname("range")
                                        .__call__(var2, var1.getname("len").__call__(var2, var1.getname("rawvers")))
                                        .__iter__();

                                while (true) {
                                    var1.setline(82);
                                    var7 = var14.__iternext__();
                                    if (var7 == null) {
                                        var1.setline(87);
                                        var14 = var1.getname("len").__call__(var2, var1.getname("vercurgrp"));
                                        var10000 = var14._gt(Py.newInteger(0));
                                        var6 = null;
                                        if (var10000.__nonzero__()) {
                                            var1.setline(88);
                                            if (var1.getname("re").__getattr__("match")
                                                    .__call__(var2, PyString.fromInterned("v"),
                                                            var1.getname("trcdata").__getitem__(Py.newInteger(0)),
                                                            var1.getname("re").__getattr__("I"))
                                                    .__nonzero__()) {
                                                var1.setline(89);
                                                var1.getname("vergroup").__getattr__("append").__call__(var2,
                                                        Py.newInteger(0)
                                                        ._add(var1.getname("vercurgrp")
                                                                .__getitem__(Py.newInteger(0))
                                                                ._mul(Py.newImaginary(1.0D))));
                                            } else {
                                                var1.setline(90);
                                                if (var1.getname("re").__getattr__("match")
                                                        .__call__(var2, PyString.fromInterned("h"),
                                                                var1.getname("trcdata").__getitem__(Py.newInteger(0)),
                                                                var1.getname("re").__getattr__("I"))
                                                        .__nonzero__()) {
                                                    var1.setline(91);
                                                    var1.getname("vergroup").__getattr__("append").__call__(var2,
                                                            var1.getname("vercurgrp").__getitem__(Py.newInteger(0))
                                                            ._add(Py.newImaginary(0.0D)));
                                                }
                                            }
                                        }

                                        var1.setline(92);
                                        var1.getname("trcdata").__getattr__("append").__call__(var2,
                                                var1.getname("vergroup"));
                                        var1.setline(93);
                                        var1.getname("trDatas").__getattr__("append").__call__(var2,
                                                var1.getname("trcdata"));
                                        continue label182;
                                    }

                                    var1.setlocal("st", var7);
                                    var1.setline(83);
                                    var1.getname("vercurgrp").__getattr__("append").__call__(var2,
                                            var1.getname("rawvers").__getitem__(var1.getname("st")));
                                    var1.setline(84);
                                    var8 = var1.getname("len").__call__(var2, var1.getname("vercurgrp"));
                                    var10000 = var8._ge(Py.newInteger(2));
                                    var8 = null;
                                    if (var10000.__nonzero__()) {
                                        var1.setline(85);
                                        var1.getname("vergroup").__getattr__("append").__call__(var2,
                                                var1.getname("vercurgrp").__getitem__(Py.newInteger(0))
                                                ._add(var1.getname("vercurgrp").__getitem__(Py.newInteger(1))
                                                        ._mul(Py.newImaginary(1.0D))));
                                        var1.setline(86);
                                        PyList var17 = new PyList(Py.EmptyObjects);
                                        var1.getname("vercurgrp").__setslice__((PyObject) null, (PyObject) null,
                                                (PyObject) null, var17);
                                        var8 = null;
                                    }
                                }
                            }

                            var1.setlocal("st", var7);
                            var1.setline(79);
                            var8 = var1.getname("float").__call__(var2,
                                    var1.getname("rawvers").__getitem__(var1.getname("st")));
                            var1.getname("rawvers").__setitem__(var1.getname("st"), var8);
                            var8 = null;
                        }
                    }
                } catch (Throwable var11) {
                    if (var23.__exit__(var2, Py.setException(var11, var1))) {
                        break label188;
                    }

                    throw Py.makeException();
                }

                var23.__exit__(var2, (PyException) null);
            }

            var1.setline(96);
            var13 = var1.getname("range")
                    .__call__(var2, Py.newInteger(1), var1.getname("len").__call__(var2, var1.getname("trDatas")))
                    .__iter__();

            label166: while (true) {
                var1.setline(96);
                var4 = var13.__iternext__();
                PyObject var9;
                if (var4 == null) {
                    var1.setline(100);
                    var13 = var1.getname("range")
                            .__call__(var2, var1.getname("len").__call__(var2, var1.getname("trDatas"))).__iter__();

                    while (true) {
                        var1.setline(100);
                        var4 = var13.__iternext__();
                        if (var4 == null) {
                            var1.setline(110);
                            var13 = var1.getname("range")
                                    .__call__(var2, var1.getname("len").__call__(var2, var1.getname("trDatas")))
                                    .__iter__();

                            while (true) {
                                var1.setline(110);
                                var4 = var13.__iternext__();
                                if (var4 == null) {
                                    var1.setline(114);
                                    var13 = var1.getname("range")
                                            .__call__(var2, var1.getname("len").__call__(var2, var1.getname("points")))
                                            .__iter__();

                                    while (true) {
                                        var1.setline(114);
                                        var4 = var13.__iternext__();
                                        if (var4 == null) {
                                            var1.setline(118);
                                            Py.println(PyString.fromInterned("Weight process start."));
                                            var1.setline(119);
                                            var21 = Py.newInteger(0);
                                            var1.setlocal("wsum", var21);
                                            var3 = null;
                                            var1.setline(120);
                                            var13 = var1.getname("points").__iter__();

                                            while (true) {
                                                var1.setline(120);
                                                var4 = var13.__iternext__();
                                                if (var4 == null) {
                                                    var1.setline(128);
                                                    var13 = var1
                                                            .getname("range").__call__(var2, var1.getname("len")
                                                                    .__call__(var2, var1.getname("curWeight")))
                                                            .__iter__();

                                                    while (true) {
                                                        var1.setline(128);
                                                        var4 = var13.__iternext__();
                                                        if (var4 == null) {
                                                            var1.setline(130);
                                                            var13 = var1.getname("range")
                                                                    .__call__(var2, Py.newInteger(1),
                                                                            var1.getname("len").__call__(var2,
                                                                                    var1.getname("curWeight")))
                                                                    .__iter__();

                                                            while (true) {
                                                                var1.setline(130);
                                                                var4 = var13.__iternext__();
                                                                if (var4 == null) {
                                                                    var1.setline(132);
                                                                    var1.getname("curWeight").__getattr__("insert")
                                                                    .__call__(var2, Py.newInteger(0),
                                                                            Py.newInteger(0));
                                                                    var1.setline(133);
                                                                    var21 = Py.newInteger(1);
                                                                    var1.getname("curWeight")
                                                                    .__setitem__(Py.newInteger(-1), var21);
                                                                    var3 = null;
                                                                    var1.setline(134);
                                                                    Py.println(PyString
                                                                            .fromInterned("Weight process finished."));
                                                                    var1.setline(136);
                                                                    var22 = new PyList(Py.EmptyObjects);
                                                                    var1.setlocal("out", var22);
                                                                    var3 = null;
                                                                    var1.setline(137);
                                                                    Py.println(
                                                                            PyString.fromInterned("Initializing..."));
                                                                    var1.setline(138);
                                                                    var1.getname("multiprocessing")
                                                                    .__getattr__("freeze_support")
                                                                    .__call__(var2);
                                                                    var1.setline(139);
                                                                    var13 = var1.getname("multiprocessing")
                                                                            .__getattr__("Value").__call__(var2,
                                                                                    PyString.fromInterned("i"),
                                                                                    Py.newInteger(0));
                                                                    var1.setlocal("prjCur", var13);
                                                                    var3 = null;
                                                                    var1.setline(140);
                                                                    var10000 = var1.getname("multiprocessing")
                                                                            .__getattr__("Pool");
                                                                    var12 = new PyObject[] { var1.getname("initParam"),
                                                                            new PyTuple(new PyObject[] {
                                                                                    var1.getname("points"),
                                                                                    var1.getname("curWeight"),
                                                                                    var1.getname("prjCur") }) };
                                                                    String[] var18 = new String[] { "initializer",
                                                                    "initargs" };
                                                                    var10000 = var10000.__call__(var2, var12, var18);
                                                                    var3 = null;
                                                                    var13 = var10000;
                                                                    var1.setlocal("pool", var13);
                                                                    var3 = null;
                                                                    var1.setline(141);
                                                                    Py.println(PyString
                                                                            .fromInterned("Initializing finished."));
                                                                    var1.setline(142);
                                                                    Py.println(PyString
                                                                            .fromInterned("Main calculation start."));
                                                                    var1.setline(143);
                                                                    var13 = var1.getname("pool")
                                                                            .__getattr__("map_async").__call__(var2,
                                                                                    var1.getname("mainCalculation"),
                                                                                    var1.getname("range").__call__(var2,
                                                                                            var1.getname("start"),
                                                                                            var1.getname("end")._add(
                                                                                                    Py.newInteger(1))));
                                                                    var1.setlocal("out", var13);
                                                                    var3 = null;
                                                                    var1.setline(144);
                                                                    var21 = Py.newInteger(50);
                                                                    var1.setlocal("division", var21);
                                                                    var3 = null;

                                                                    while (true) {
                                                                        var1.setline(145);
                                                                        if (!var1.getname("True").__nonzero__()) {
                                                                            break;
                                                                        }

                                                                        var1.setline(146);
                                                                        var13 = var1.getname("prjCur")
                                                                                .__getattr__("value")
                                                                                ._truediv(var1.getname("prjNum"));
                                                                        var1.setlocal("percentage", var13);
                                                                        var3 = null;
                                                                        var1.setline(147);
                                                                        var13 = var1.getname("round").__call__(var2,
                                                                                var1.getname("percentage")._mul(
                                                                                        var1.getname("division")));
                                                                        var1.setlocal("nump", var13);
                                                                        var3 = null;
                                                                        var1.setline(149);
                                                                        Py.println(PyString
                                                                                .fromInterned("[{}{}] {:.0%}")
                                                                                .__getattr__("format")
                                                                                .__call__(var2, PyString
                                                                                        .fromInterned("=")
                                                                                        ._mul(var1.getname("int")
                                                                                                .__call__(var2,
                                                                                                        var1.getname(
                                                                                                                "nump"))),
                                                                                        PyString.fromInterned(" ")
                                                                                        ._mul(var1
                                                                                                .getname("int")
                                                                                                .__call__(var2,
                                                                                                        var1.getname(
                                                                                                                "division")
                                                                                                        ._sub(var1
                                                                                                                .getname(
                                                                                                                        "nump")))),
                                                                                        var1.getname("percentage")));
                                                                        var1.setline(150);
                                                                        var13 = var1.getname("prjCur")
                                                                                .__getattr__("value");
                                                                        var10000 = var13._ge(var1.getname("prjNum"));
                                                                        var3 = null;
                                                                        if (var10000.__nonzero__()) {
                                                                            var1.setline(151);
                                                                            Py.println(new PyTuple(Py.EmptyObjects));
                                                                            break;
                                                                        }

                                                                        var1.setline(153);
                                                                        var1.getname("time").__getattr__("sleep")
                                                                        .__call__(var2, Py.newFloat(0.1D));
                                                                    }

                                                                    var1.setline(154);
                                                                    var1.getname("pool").__getattr__("close")
                                                                    .__call__(var2);
                                                                    var1.setline(155);
                                                                    var1.getname("pool").__getattr__("join")
                                                                    .__call__(var2);
                                                                    var1.setline(156);
                                                                    var1.getname("out").__getattr__("wait")
                                                                    .__call__(var2);
                                                                    var1.setline(157);
                                                                    var13 = var1.getname("out").__getattr__("get")
                                                                            .__call__(var2);
                                                                    var1.setlocal("out", var13);
                                                                    var3 = null;
                                                                    var1.setline(158);
                                                                    Py.println(PyString.fromInterned(
                                                                            "Main calculation finished."));
                                                                    var4 = (var23 = ContextGuard.getManager(
                                                                            var1.getname("open").__call__(var2,
                                                                                    PyString.fromInterned("datas.txt"),
                                                                                    PyString.fromInterned("w"))))
                                                                            .__enter__(var2);

                                                                    label100: {
                                                                        try {
                                                                            var1.setlocal("File", var4);
                                                                            var1.setline(160);
                                                                            var4 = var1.getname("out").__iter__();

                                                                            while (true) {
                                                                                var1.setline(160);
                                                                                var5 = var4.__iternext__();
                                                                                if (var5 == null) {
                                                                                    break;
                                                                                }

                                                                                var1.setlocal("dc", var5);
                                                                                var1.setline(161);
                                                                                var1.getname("File")
                                                                                .__getattr__("write")
                                                                                .__call__(var2, PyString
                                                                                        .fromInterned("{0}")
                                                                                        .__getattr__("format")
                                                                                        .__call__(var2,
                                                                                                var1.getname(
                                                                                                        "dc")));
                                                                                var1.setline(162);
                                                                                var1.getname("File")
                                                                                .__getattr__("write")
                                                                                .__call__(var2, PyString
                                                                                        .fromInterned("\n"));
                                                                            }
                                                                        } catch (Throwable var10) {
                                                                            if (var23.__exit__(var2,
                                                                                    Py.setException(var10, var1))) {
                                                                                break label100;
                                                                            }

                                                                            throw Py.makeException();
                                                                        }

                                                                        var23.__exit__(var2, (PyException) null);
                                                                    }

                                                                    var1.setline(163);
                                                                    Py.println(PyString.fromInterned(
                                                                            "Data saved.\n\nWork finished.\n"));
                                                                    break label166;
                                                                }

                                                                var1.setlocal("i", var4);
                                                                var1.setline(131);
                                                                var10000 = var1.getname("curWeight");
                                                                var5 = var1.getname("i");
                                                                var14 = var10000;
                                                                var7 = var14.__getitem__(var5);
                                                                var7 = var7._iadd(var1.getname("curWeight").__getitem__(
                                                                        var1.getname("i")._sub(Py.newInteger(1))));
                                                                var14.__setitem__(var5, var7);
                                                            }
                                                        }

                                                        var1.setlocal("i", var4);
                                                        var1.setline(129);
                                                        var10000 = var1.getname("curWeight");
                                                        var5 = var1.getname("i");
                                                        var14 = var10000;
                                                        var7 = var14.__getitem__(var5);
                                                        var7 = var7._itruediv(var1.getname("wsum"));
                                                        var14.__setitem__(var5, var7);
                                                    }
                                                }

                                                var1.setlocal("curve", var4);
                                                var1.setline(121);
                                                PyInteger var16 = Py.newInteger(10);
                                                var1.setlocal("wst", var16);
                                                var5 = null;
                                                var1.setline(122);
                                                var16 = Py.newInteger(0);
                                                var1.setlocal("sum", var16);
                                                var5 = null;
                                                var1.setline(123);
                                                var5 = var1.getname("range")
                                                        .__call__(var2, Py.newInteger(1), var1.getname("wst"))
                                                        .__iter__();

                                                while (true) {
                                                    var1.setline(123);
                                                    var14 = var5.__iternext__();
                                                    if (var14 == null) {
                                                        var1.setline(126);
                                                        var1.getname("curWeight").__getattr__("append").__call__(var2,
                                                                var1.getname("sum"));
                                                        var1.setline(127);
                                                        var5 = var1.getname("wsum");
                                                        var5 = var5._iadd(var1.getname("sum"));
                                                        var1.setlocal("wsum", var5);
                                                        break;
                                                    }

                                                    var1.setlocal("i", var14);
                                                    var1.setline(124);
                                                    var7 = var1.getname("sum");
                                                    var10000 = var1.getname("abs");
                                                    PyObject var10002 = var1.getname("bezier");
                                                    PyObject[] var20 = new PyObject[5];
                                                    PyObject var10004 = var1.getname("linear");
                                                    PyObject[] var19 = new PyObject[] { var1.getname("i"),
                                                            Py.newInteger(0), var1.getname("wst"), Py.newInteger(0),
                                                            Py.newInteger(1) };
                                                    var20[0] = var10004.__call__(var2, var19);
                                                    var20[1] = var1.getname("curve").__getitem__(Py.newInteger(0));
                                                    var20[2] = var1.getname("curve").__getitem__(Py.newInteger(1));
                                                    var20[3] = var1.getname("curve").__getitem__(Py.newInteger(2));
                                                    var20[4] = var1.getname("curve").__getitem__(Py.newInteger(3));
                                                    var10002 = var10002.__call__(var2, var20);
                                                    PyObject var10003 = var1.getname("bezier");
                                                    var20 = new PyObject[5];
                                                    PyObject var10005 = var1.getname("linear");
                                                    var19 = new PyObject[] { var1.getname("i")._sub(Py.newInteger(1)),
                                                            Py.newInteger(0), var1.getname("wst"), Py.newInteger(0),
                                                            Py.newInteger(1) };
                                                    var20[0] = var10005.__call__(var2, var19);
                                                    var20[1] = var1.getname("curve").__getitem__(Py.newInteger(0));
                                                    var20[2] = var1.getname("curve").__getitem__(Py.newInteger(1));
                                                    var20[3] = var1.getname("curve").__getitem__(Py.newInteger(2));
                                                    var20[4] = var1.getname("curve").__getitem__(Py.newInteger(3));
                                                    var7 = var7._iadd(var10000.__call__(var2,
                                                            var10002._sub(var10003.__call__(var2, var20))));
                                                    var1.setlocal("sum", var7);
                                                }
                                            }
                                        }

                                        var1.setlocal("i", var4);
                                        var1.setline(115);
                                        var5 = var1.getname("range")
                                                .__call__(var2,
                                                        var1.getname("len").__call__(var2,
                                                                var1.getname("points").__getitem__(var1.getname("i"))))
                                                .__iter__();

                                        while (true) {
                                            var1.setline(115);
                                            var14 = var5.__iternext__();
                                            if (var14 == null) {
                                                break;
                                            }

                                            var1.setlocal("j", var14);
                                            var1.setline(116);
                                            var10000 = var1.getname("points").__getitem__(var1.getname("i"));
                                            var7 = var1.getname("j");
                                            var8 = var10000;
                                            var9 = var8.__getitem__(var7);
                                            var9 = var9._isub(var1.getname("center").__getitem__(Py.newInteger(0))
                                                    ._add(Py.newImaginary(1.0D)._mul(
                                                            var1.getname("center").__getitem__(Py.newInteger(1)))));
                                            var8.__setitem__(var7, var9);
                                        }
                                    }
                                }

                                var1.setlocal("i", var4);
                                var1.setline(111);
                                var5 = var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(0));
                                var1.setlocal("flag", var5);
                                var5 = null;
                                var1.setline(112);
                                if (!var1
                                        .getname("re").__getattr__("match").__call__(var2, PyString.fromInterned("m"),
                                                var1.getname("flag"), var1.getname("re").__getattr__("I"))
                                        .__nonzero__()) {
                                    var1.setline(113);
                                    var1.getname("points").__getattr__("append").__call__(var2, var1.getname("trDatas")
                                            .__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1)));
                                }
                            }
                        }

                        var1.setlocal("i", var4);
                        var1.setline(101);
                        var5 = var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(0));
                        var1.setlocal("flag", var5);
                        var5 = null;
                        var1.setline(102);
                        if (!var1.getname("re").__getattr__("match").__call__(var2, PyString.fromInterned("m"),
                                var1.getname("flag"), var1.getname("re").__getattr__("I")).__nonzero__()) {
                            var1.setline(103);
                            var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                            .__getattr__("insert").__call__(var2, Py.newInteger(0),
                                    var1.getname("trDatas")
                                    .__getitem__(var1.getname("i")._sub(Py.newInteger(1)))
                                    .__getitem__(Py.newInteger(1)).__getitem__(Py.newInteger(-1)));
                            var1.setline(104);
                            if (var1.getname("re").__getattr__("match").__call__(var2, PyString.fromInterned("s"),
                                    var1.getname("flag"), var1.getname("re").__getattr__("I")).__nonzero__()) {
                                var1.setline(105);
                                var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                                .__getattr__("insert").__call__(var2, Py.newInteger(1),
                                        Py.newInteger(2)._mul(var1.getname("trDatas")
                                                .__getitem__(var1.getname("i")._sub(Py.newInteger(1)))
                                                .__getitem__(Py.newInteger(1)).__getitem__(Py.newInteger(-1)))
                                        ._sub(var1.getname("trDatas")
                                                .__getitem__(var1.getname("i")._sub(Py.newInteger(1)))
                                                .__getitem__(Py.newInteger(1))
                                                .__getitem__(Py.newInteger(-2))));
                            }

                            var1.setline(106);
                            if (var1.getname("re").__getattr__("match").__call__(var2, PyString.fromInterned("[lvh]"),
                                    var1.getname("flag"), var1.getname("re").__getattr__("I")).__nonzero__()) {
                                var1.setline(107);
                                var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                                .__getattr__("insert")
                                .__call__(var2, Py.newInteger(1), var1.getname("trDatas")
                                        .__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                                        .__getitem__(Py.newInteger(0))._truediv(Py.newInteger(3))
                                        ._add(var1.getname("trDatas").__getitem__(var1.getname("i"))
                                                .__getitem__(Py.newInteger(1)).__getitem__(Py.newInteger(-1))
                                                ._mul(Py.newInteger(2))._truediv(Py.newInteger(3))));
                                var1.setline(108);
                                var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                                .__getattr__("insert")
                                .__call__(var2, Py.newInteger(1), var1.getname("trDatas")
                                        .__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))
                                        .__getitem__(Py.newInteger(0))._mul(Py.newInteger(2))
                                        ._truediv(Py.newInteger(3))
                                        ._add(var1.getname("trDatas").__getitem__(var1.getname("i"))
                                                .__getitem__(Py.newInteger(1)).__getitem__(Py.newInteger(-1))
                                                ._truediv(Py.newInteger(3))));
                            }
                        }
                    }
                }

                var1.setlocal("i", var4);
                var1.setline(97);
                if (var1.getname("re").__getattr__("match")
                        .__call__(var2, PyString.fromInterned("[a-z]"),
                                var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(0)))
                        .__nonzero__()) {
                    var1.setline(98);
                    var5 = var1
                            .getname(
                                    "range")
                            .__call__(var2, var1.getname("len").__call__(var2, var1.getname("trDatas")
                                    .__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1))))
                            .__iter__();

                    while (true) {
                        var1.setline(98);
                        var14 = var5.__iternext__();
                        if (var14 == null) {
                            break;
                        }

                        var1.setlocal("j", var14);
                        var1.setline(99);
                        var10000 = var1.getname("trDatas").__getitem__(var1.getname("i")).__getitem__(Py.newInteger(1));
                        var7 = var1.getname("j");
                        var8 = var10000;
                        var9 = var8.__getitem__(var7);
                        var9 = var9._iadd(var1.getname("trDatas").__getitem__(var1.getname("i")._sub(Py.newInteger(1)))
                                .__getitem__(Py.newInteger(1)).__getitem__(Py.newInteger(-1)));
                        var8.__setitem__(var7, var9);
                    }
                }
            }
        }

        var1.f_lasti = -1;
        return Py.None;
    }

    public PyObject bezier$1(PyFrame var1, ThreadState var2) {
        var1.setline(12);
        PyObject var3 = var1.getlocal(1).__neg__()._add(Py.newInteger(3)._mul(var1.getlocal(2)))
                ._sub(Py.newInteger(3)._mul(var1.getlocal(3)))._add(var1.getlocal(4))._mul(var1.getlocal(0))
                ._mul(var1.getlocal(0))._mul(var1.getlocal(0))
                ._add(Py.newInteger(3)
                        ._mul(var1.getlocal(1)._sub(Py.newInteger(2)._mul(var1.getlocal(2)))._add(var1.getlocal(3)))
                        ._mul(var1.getlocal(0))._mul(var1.getlocal(0)))
                ._add(Py.newInteger(3)._mul(var1.getlocal(1).__neg__()._add(var1.getlocal(2)))._mul(var1.getlocal(0)))
                ._add(var1.getlocal(1));
        var1.f_lasti = -1;
        return var3;
    }

    public PyObject linear$2(PyFrame var1, ThreadState var2) {
        var1.setline(15);
        PyObject var3 = var1.getlocal(0)._sub(var1.getlocal(1))._truediv(var1.getlocal(2)._sub(var1.getlocal(1)))
                ._mul(var1.getlocal(4)._sub(var1.getlocal(3)))._add(var1.getlocal(3));
        var1.f_lasti = -1;
        return var3;
    }

    public PyObject prSolve$3(PyFrame var1, ThreadState var2) {
        var1.setline(20);
        PyObject var3 = var1.getlocal(0);
        PyObject var10000 = var3._eq(Py.newInteger(0));
        var3 = null;
        if (var10000.__nonzero__()) {
            var1.setline(21);
            var3 = var1.getlocal(2)._sub(var1.getlocal(1))._mul(var1.getglobal("oneOver2PI"))
                    ._truediv(var1.getlocal(3)._add(Py.newInteger(1)));
            var1.f_lasti = -1;
            return var3;
        } else {
            var1.setline(22);
            PyObject var4 = var1.getlocal(3);
            var10000 = var4._eq(Py.newInteger(0));
            var4 = null;
            if (var10000.__nonzero__()) {
                var1.setline(23);
                var3 = Py.newImaginary(1.0D)._mul(var1.getglobal("oneOver2PI"))._truediv(var1.getlocal(0))._mul(var1
                        .getglobal("cmath").__getattr__("exp")
                        .__call__(var2, var1.getlocal(0).__neg__()._mul(Py.newImaginary(1.0D))._mul(var1.getlocal(2)))
                        ._sub(var1.getglobal("cmath").__getattr__("exp").__call__(var2,
                                var1.getlocal(0).__neg__()._mul(Py.newImaginary(1.0D))._mul(var1.getlocal(1)))));
                var1.f_lasti = -1;
                return var3;
            } else {
                var1.setline(24);
                var4 = var1.getlocal(3);
                var10000 = var4._gt(Py.newInteger(0));
                var4 = null;
                if (var10000.__nonzero__()) {
                    var1.setline(25);
                    var3 = Py.newImaginary(1.0D)._mul(var1.getglobal("oneOver2PI"))._truediv(var1.getlocal(0))
                            ._mul(var1.getglobal("cmath").__getattr__("exp").__call__(var2,
                                    var1.getlocal(0).__neg__()._mul(Py.newImaginary(1.0D))._mul(var1.getlocal(2))))
                            ._sub(var1.getlocal(3)._mul(Py.newImaginary(1.0D))
                                    ._truediv(var1.getlocal(2)._sub(var1.getlocal(1))._mul(var1.getlocal(0)))
                                    ._mul(var1.getglobal("prSolve").__call__(var2, var1.getlocal(0), var1.getlocal(1),
                                            var1.getlocal(2), var1.getlocal(3)._sub(Py.newInteger(1)))));
                    var1.f_lasti = -1;
                    return var3;
                } else {
                    var1.setline(27);
                    PyInteger var5 = Py.newInteger(0);
                    var1.f_lasti = -1;
                    return var5;
                }
            }
        }
    }

    public PyObject numSolve$4(PyFrame var1, ThreadState var2) {
        var1.setline(30);
        PyObject var3 = var1.getlocal(3).__getitem__(Py.newInteger(0)).__neg__()
                ._add(Py.newInteger(3)._mul(var1.getlocal(3).__getitem__(Py.newInteger(1))))
                ._sub(Py.newInteger(3)._mul(var1.getlocal(3).__getitem__(Py.newInteger(2))))
                ._add(var1.getlocal(3).__getitem__(Py.newInteger(3)))
                ._mul(var1.getglobal("prSolve").__call__(var2, var1.getlocal(0), var1.getlocal(1), var1.getlocal(2),
                        Py.newInteger(3)))
                ._add(Py.newInteger(3)
                        ._mul(var1.getlocal(3).__getitem__(Py.newInteger(0))
                                ._sub(Py.newInteger(2)._mul(var1.getlocal(3).__getitem__(Py.newInteger(1))))
                                ._add(var1.getlocal(3).__getitem__(Py.newInteger(2))))
                        ._mul(var1.getglobal("prSolve").__call__(var2, var1.getlocal(0), var1.getlocal(1),
                                var1.getlocal(2), Py.newInteger(2))))
                ._add(Py.newInteger(3)
                        ._mul(var1.getlocal(3).__getitem__(Py.newInteger(0)).__neg__()
                                ._add(var1.getlocal(3).__getitem__(Py.newInteger(1))))
                        ._mul(var1.getglobal("prSolve").__call__(var2, var1.getlocal(0), var1.getlocal(1),
                                var1.getlocal(2), Py.newInteger(1))))
                ._add(var1.getlocal(3).__getitem__(Py.newInteger(0))._mul(var1.getglobal("prSolve").__call__(var2,
                        var1.getlocal(0), var1.getlocal(1), var1.getlocal(2), Py.newInteger(0))));
        var1.f_lasti = -1;
        return var3;
    }

    public PyObject cpToList$5(PyFrame var1, ThreadState var2) {
        var1.setline(34);
        PyList var3 = new PyList(
                new PyObject[] { var1.getlocal(0).__getattr__("real"), var1.getlocal(0).__getattr__("imag") });
        var1.f_lasti = -1;
        return var3;
    }

    public PyObject initParam$6(PyFrame var1, ThreadState var2) {
        var1.setline(48);
        PyObject var3 = var1.getlocal(0);
        var1.setglobal("points", var3);
        var3 = null;
        var1.setline(49);
        var3 = var1.getlocal(1);
        var1.setglobal("curWeight", var3);
        var3 = null;
        var1.setline(50);
        var3 = var1.getlocal(2);
        var1.setglobal("prjCur", var3);
        var3 = null;
        var1.f_lasti = -1;
        return Py.None;
    }

    public PyObject mainCalculation$7(PyFrame var1, ThreadState var2) {
        var1.f_exits = new PyObject[1];
        var1.setline(54);
        PyInteger var3 = Py.newInteger(0);
        var1.setlocal(1, var3);
        var3 = null;
        var1.setline(55);
        PyObject var8 = var1.getlocal(0);
        PyObject var10000 = var8._gt(Py.newInteger(0));
        var3 = null;
        if (var10000.__nonzero__()) {
            var1.setline(56);
            var10000 = var1.getlocal(0)._add(Py.newInteger(1))._floordiv(Py.newInteger(2));
            var1.setline(56);
            var8 = var1.getlocal(0)._mod(Py.newInteger(2));
            PyObject var10001 = var8._eq(Py.newInteger(0));
            var3 = null;
            var8 = var10000._mul(var10001.__nonzero__() ? Py.newInteger(-1) : Py.newInteger(1));
            var1.setlocal(1, var8);
            var3 = null;
        }

        var1.setline(58);
        PyComplex var11 = Py.newImaginary(0.0D);
        var1.setlocal(2, var11);
        var3 = null;
        var1.setline(59);
        var8 = var1.getglobal("range").__call__(var2, var1.getglobal("len").__call__(var2, var1.getglobal("points")))
                .__iter__();

        while (true) {
            var1.setline(59);
            PyObject var4 = var8.__iternext__();
            PyObject var10;
            if (var4 == null) {
                ContextManager var12;
                var4 = (var12 = ContextGuard
                        .getManager(var1.getglobal("prjCur").__getattr__("get_lock").__call__(var2))).__enter__(var2);

                label28: {
                    try {
                        var1.setline(64);
                        var10000 = var1.getglobal("prjCur");
                        String var9 = "value";
                        var10 = var10000;
                        PyObject var6 = var10.__getattr__(var9);
                        var6 = var6._iadd(Py.newInteger(1));
                        var10.__setattr__(var9, var6);
                    } catch (Throwable var7) {
                        if (var12.__exit__(var2, Py.setException(var7, var1))) {
                            break label28;
                        }

                        throw Py.makeException();
                    }

                    var12.__exit__(var2, (PyException) null);
                }

                var1.setline(65);
                var8 = var1.getglobal("cpToList").__call__(var2, var1.getlocal(2));
                var1.f_lasti = -1;
                return var8;
            }

            var1.setlocal(3, var4);
            var1.setline(60);
            var10000 = var1.getglobal("linear");
            PyObject[] var5 = new PyObject[] { var1.getglobal("curWeight").__getitem__(var1.getlocal(3)),
                    Py.newInteger(0), Py.newInteger(1), Py.newInteger(0),
                    var1.getglobal("math").__getattr__("pi")._mul(Py.newInteger(2)) };
            var10 = var10000.__call__(var2, var5);
            var1.setlocal(4, var10);
            var5 = null;
            var1.setline(61);
            var10000 = var1.getglobal("linear");
            var5 = new PyObject[] { var1.getglobal("curWeight").__getitem__(var1.getlocal(3)._add(Py.newInteger(1))),
                    Py.newInteger(0), Py.newInteger(1), Py.newInteger(0),
                    var1.getglobal("math").__getattr__("pi")._mul(Py.newInteger(2)) };
            var10 = var10000.__call__(var2, var5);
            var1.setlocal(5, var10);
            var5 = null;
            var1.setline(62);
            var10 = var1.getlocal(2);
            var10 = var10._iadd(var1.getglobal("numSolve").__call__(var2, var1.getlocal(1), var1.getlocal(4),
                    var1.getlocal(5), var1.getglobal("points").__getitem__(var1.getlocal(3))));
            var1.setlocal(2, var10);
        }
    }

    public FourierMath$py(String var1) {
        self = this;
        String[] var2 = new String[0];
        f$0 = Py.newCode(0, var2, var1, "<module>", 0, false, false, self, 0, (String[]) null, (String[]) null, 0,
                12288);
        var2 = new String[] { "t", "a", "b", "c", "d" };
        bezier$1 = Py.newCode(5, var2, var1, "bezier", 11, false, false, self, 1, (String[]) null, (String[]) null, 0,
                12289);
        var2 = new String[] { "x", "a", "b", "c", "d" };
        linear$2 = Py.newCode(5, var2, var1, "linear", 14, false, false, self, 2, (String[]) null, (String[]) null, 0,
                12289);
        var2 = new String[] { "m", "cs", "ce", "n" };
        prSolve$3 = Py.newCode(4, var2, var1, "prSolve", 19, false, false, self, 3, (String[]) null, (String[]) null, 0,
                12289);
        var2 = new String[] { "m", "cs", "ce", "pts" };
        numSolve$4 = Py.newCode(4, var2, var1, "numSolve", 29, false, false, self, 4, (String[]) null, (String[]) null,
                0, 12289);
        var2 = new String[] { "cp" };
        cpToList$5 = Py.newCode(1, var2, var1, "cpToList", 33, false, false, self, 5, (String[]) null, (String[]) null,
                0, 12289);
        var2 = new String[] { "pts", "cw", "pjc" };
        initParam$6 = Py.newCode(3, var2, var1, "initParam", 46, false, false, self, 6, (String[]) null,
                (String[]) null, 0, 12289);
        var2 = new String[] { "s", "m", "sum", "i", "cs", "ce" };
        mainCalculation$7 = Py.newCode(1, var2, var1, "mainCalculation", 52, false, false, self, 7, (String[]) null,
                (String[]) null, 0, 12289);
    }

    @Override
    public PyCode getMain() {
        return f$0;
    }

    public static void main(String[] var0) throws Exception {
        Py.runMain(CodeLoader.createSimpleBootstrap((new FourierMath$py("FourierMath$py")).getMain()), var0);
    }

    public static CodeBootstrap getCodeBootstrap() {
        return PyRunnableBootstrap.getFilenameConstructorReflectionBootstrap(FourierMath$py.class);
    }

    @Override
    public PyObject call_function(int var1, PyFrame var2, ThreadState var3) {
        switch (var1) {
            case 0:
                return this.f$0(var2, var3);
            case 1:
                return this.bezier$1(var2, var3);
            case 2:
                return this.linear$2(var2, var3);
            case 3:
                return this.prSolve$3(var2, var3);
            case 4:
                return this.numSolve$4(var2, var3);
            case 5:
                return this.cpToList$5(var2, var3);
            case 6:
                return this.initParam$6(var2, var3);
            case 7:
                return this.mainCalculation$7(var2, var3);
            default:
                return null;
        }
    }
}