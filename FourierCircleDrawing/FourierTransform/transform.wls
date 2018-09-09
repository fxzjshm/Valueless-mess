#!/usr/bin/env wolframscript
(* ::Package:: *)

f[image_, method_: 1, range_: 2, threshold_: 0.2, random_: 2, 
  linenumber_: 10, terms_: 10, order_: 3, detail_: 64*Pi, 
  points_: 100] := Module[{},
  (*\:5f00\:59cb\:521d\:59cb\:5316*)
  fourierComponentData[pointList_, nMax_, op_] := 
   Module[{\[CurlyEpsilon] = 10^-3, \[Mu] = 2^14, M = 10000, s,
                  scale, \[CapitalDelta], L , nds, sMax, 
     if, \[ScriptX]\[ScriptY]Function, X, Y, XFT, YFT, type},
    (* prepare curve *)
    scale = 
     1. Mean[Table[ 
        Max[ fl /@ pointList] - 
         Min[fl /@ pointList], {fl, {First, Last}}]];
     \[CapitalDelta] = 
     EuclideanDistance[First[pointList], Last[pointList]];
     L = Which[op === "Closed", type = "Closed";
                                                              
      If[First[pointList] === Last[pointList], 
                                                                  
       pointList, Append[pointList, First[pointList]]], 
                      op === "Open", type = "Open"; pointList,
                       \[CapitalDelta] == 0., type = "Closed";  
      pointList,
                       \[CapitalDelta]/scale < op, type = "Closed"; 
      Append[pointList, First[pointList]],
                      True,  type = "Open"; 
      Join[pointList, Rest[Reverse[pointList]]]];
    (* re-parametrize curve by arclength *)
    \[ScriptX]\[ScriptY]Function = 
     BSplineFunction[L, SplineDegree -> 4];
    nds = 
     NDSolve[{s'[t] == 
        Sqrt[\[ScriptX]\[ScriptY]Function'[
           t].\[ScriptX]\[ScriptY]Function'[t]], s[0] == 0}, s, 
                                {t, 0, 1}, MaxSteps -> 10^5, 
      PrecisionGoal -> 4];
    (* total curve length *)
         sMax = s[1] /. nds[[1]];
         if = 
     Interpolation[
      Table[{s[\[Sigma]] /. nds[[1]], \[Sigma]}, {\[Sigma], 0, 1, 
        1/M}]];
    X[t_Real] :=  
     BSplineFunction[L][Max[Min[1, if[(t + Pi)/(2 Pi) sMax]] , 0]][[
      1]];
    Y[t_Real] :=  
     BSplineFunction[L][Max[Min[1, if[(t + Pi)/(2 Pi) sMax]] , 0]][[
      2]]; 
    (* extract Fourier coefficients *)
    {XFT, YFT} = 
     Fourier[Table[#[N @ t], {t, -Pi + \[CurlyEpsilon], 
          Pi - \[CurlyEpsilon], (2 Pi - 
             2 \[CurlyEpsilon])/\[Mu]}]] & /@ {X, Y};   
    {type, 2 Pi/Sqrt[\[Mu]] *
      ((Transpose[
           Table[{Re[#], Im[#]} &[Exp[I k Pi]  #[[k + 1]]], {k, 0, 
             nMax}]] & /@ {XFT, YFT}))}  ];
  pointListToLines[pointList_, neighborhoodSize_: 6] := 
   Module[{L = DeleteDuplicates[pointList], NF, \[Lambda], lineBag, 
     counter, seenQ, sLB, nearest,  
                 nearest1, nextPoint, 
     couldReverseQ,  \[ScriptD], \[ScriptN], \[ScriptS]},
    NF = Nearest[L] ;
         \[Lambda] = Length[L];
    Monitor[
     (* list of segments *)
     lineBag = {};
     counter = 0; 
     While[counter < \[Lambda],
      (* new segment *)
      sLB = {RandomChoice[DeleteCases[L, _?seenQ]]}; 
      seenQ[sLB[[1]]] = True;
      counter++;
      couldReverseQ = True;
      (* complete segment *)
      While[(nearest = NF[Last[sLB], {Infinity, neighborhoodSize}];
                   
        nearest1 = 
         SortBy[DeleteCases[nearest, _?seenQ], 
          1. EuclideanDistance[Last[sLB], #] &];
                   nearest1 =!= {} || couldReverseQ),
                    If[nearest1 === {},
                     (* extend the other end; 
        penalize sharp edges *)
                     sLB = Reverse[sLB]; couldReverseQ = False,
                    (* prefer straight continuation *)
                     nextPoint = If[Length[sLB] <= 3, nearest1[[1]],
                                                   \[ScriptD] = 
           1. Normalize[(sLB[[-1]] - sLB[[-2]]) + 
              1/2 (sLB[[-2]] - sLB[[-3]])];
                                                   \[ScriptN] = {-1, 
             1} Reverse[\[ScriptD]];
                                                  \[ScriptS] = 
           Sort[{Sqrt[(\[ScriptD].(# - sLB[[-1]]))^2 + 
                                                                      \
      (* perpendicular *) 2 (\[ScriptN].(# - sLB[[-1]]))^2], # } & /@ 
             nearest1]; 
                                                  \[ScriptS][[1, 2]]];
                     AppendTo[sLB, nextPoint];
                    seenQ[nextPoint] = True;
                   counter++ ]];
      AppendTo[lineBag, sLB]];
     (* return segments sorted by length *)
     Reverse[SortBy[Select[lineBag , Length[#] > 12 &], Length]],
     (* monitor progress *)
     Grid[{{Text[
         Style["progress point joining", Darker[Green, 0.66]]], 
        ProgressIndicator[counter/\[Lambda]]},
                 {Text[
         Style["number of segments", Darker[Green, 0.66]]],  
        Length[lineBag] + 1}}, 
              Alignment -> Left, Dividers -> Center]]];
  Options[fourierComponents] = {"MaxOrder" -> 500, 
    "OpenClose" -> 0.025};(*MaxOrder\:662f\:6700\:591a\:6709\:591a\:5c11\:4e2aSin\:9879\:7684\:610f\:601d\:ff0c\:4f3c\:4e4e\:8d8a\:5927\:8d8a\:597d\:3002*)
  fourierComponents[pointLists_, OptionsPattern[]] := 
   Monitor[
     Table[fourierComponentData[
       pointLists[[k]],                           
                                                                      \
       If[Head[#] === List, #[[k]], #] &[ OptionValue["MaxOrder"]],
                                                                      \
       If[Head[#] === List, #[[k]], #] &[ OptionValue["OpenClose"]]],
                               {k, Length[pointLists]}],
     Grid[{{Text[
         Style["progress calculating Fourier coefficients", 
          Darker[Green, 0.66]]], 
        ProgressIndicator[k/Length[pointLists]]} }, 
              Alignment -> Left, Dividers -> Center]] /; 
    Depth[pointLists] === 4;
  makeFourierSeries[{"Closed" | 
      "Open", {{cax_, sax_}, {cay_, say_}}}, t_, n_] :=
    {Sum[If[k == 0, 1/2, 1] cax[[k + 1]] Cos[k t] + 
      sax[[k + 1]] Sin[k t], {k, 0, Min[n, Length[cax]]}],
     Sum[If[k == 0, 1/2, 1] cay[[k + 1]] Cos[k t] + 
      say[[k + 1]] Sin[k t], {k, 0, Min[n, Length[cay]]}]};
  makeFourierSeriesApproximationManipulate[fCs_, maxOrder_: 60] :=
   Manipulate[
    With[{opts = 
       Sequence[PlotStyle -> Black, Frame -> True, Axes -> False, 
                                                 FrameTicks -> None, 
        PlotRange -> All, ImagePadding -> 12]},
     Show[{
        ParametricPlot[
         Evaluate[ 
          makeFourierSeries[#, t, n] & /@ 
           Cases[fCs, {"Closed", _}]], {t, -Pi, Pi}, opts],
        ParametricPlot[
         Evaluate[ 
          makeFourierSeries[#, t, n] & /@ 
           Cases[fCs, {"Open", _}]], {t, -Pi, 0}, opts]}] // Quiet], 
    {{n, 1, "max series order"}, 1, maxOrder, 1, 
     Appearance -> "Labeled"},
    TrackedSymbols :> True, SaveDefinitions -> True];
  sinAmplitudeForm[kt_, {cF_, sF_}] := 
   With[{\[CurlyPhi] = phase[cF, sF]}, 
    Sqrt[cF^2 + sF^2] Sin[kt + \[CurlyPhi]]];
  
  phase[cF_, sF_] := With[{T = Sqrt[cF^2 + sF^2]},
    With[{g = 
       Total[
         Abs[Table[
           cF Cos[x] + sF Sin[x] -  
            T Sin[x + #1 ArcSin[cF/T] + #2], {x, 0, 1, 0.1}]]] &}, 
               
     If[g[1, 0] <   g[-1, Pi],  ArcSin[cF/T], Pi - ArcSin[cF/T]]]];
  singleParametrization[fCs_, t_, n_] :=
    UnitStep[Sign[ Sqrt[Sin[t/2]]]] *
     Sum[UnitStep[
       t - ((m - 1) 4 Pi - Pi)] UnitStep[(m - 1) 4 Pi + 3 Pi - t]*
      ({+fCs[[m, 2, 1, 1, 1]]/2 + 
         Sum[sinAmplitudeForm[
           k t, {fCs[[m, 2, 1, 1, k + 1]], fCs[[m, 2, 1, 2, k + 1]]}], 
          {k, 
           Min[If[Head[n] === List, n[[m]], n], 
            Length[fCs[[1 , 2, 1, 1]]]]}],   
         +fCs[[m, 2, 2, 1, 1]]/2 + 
         Sum[sinAmplitudeForm[
           k t, {fCs[[m, 2, 2, 1, k + 1]], fCs[[m, 2, 2, 2, k + 1]]}], 
          {k, 
           Min[If[Head[n] === List, n[[m]], n], 
            Length[fCs[[1 , 2, 1, 1]]]]}]} ),
     {m, Length[fCs]}] ;
  importedimage = (* Import[image] *) image;
  (*\:521d\:59cb\:5316\:5b8c\:6bd5*)
  (pinkPantherImage = importedimage);
  (pinkPantherEdgeImage = Thinning[EdgeDetect[ColorConvert[
       ImagePad[Image[Map[Most, ImageData[pinkPantherImage], {2}]], 
        20, White], "Grayscale"]]]);
  (*Show[pinkPantherImage,pinkPantherEdgeImage, ImageSize \[Rule] 
  360]*)
  (pinkPantherEdgeImage2 = 
     Thinning[
      EdgeDetect[Image[importedimage, "Real"], range, threshold], 1])
   (*EdgeDetect\:91cc\:ff0c\:7b2c\:4e8c\:4e09\:4e2a\:53c2\:6570\:5206\:522b\:662f\:50cf\:7d20\:8303\:56f4\:548c\:9608\:503c*)
   Print[GraphicsGrid[{{pinkPantherImage, 
       ColorNegate[pinkPantherEdgeImage], 
       ColorNegate[pinkPantherEdgeImage2]}}, ImageSize -> 720]];
  If[method == 1, 
   edgePoints = {#2, -#1} & @@@ 
     Position[ImageData[pinkPantherEdgeImage], 1, {2}], 
   edgePoints = {#2, -#1} & @@@ 
     Position[ImageData[pinkPantherEdgeImage2], 1, {2}]];
  SeedRandom[random];
  hLines = 
   pointListToLines[edgePoints, 
    linenumber];\
(*\:7b2c\:4e8c\:4e2a\:53c2\:6570\:63a7\:5236\:7740\:6709\:591a\:8fdc\:4e0d\:5728\:540c\:4e00\:6761\:7ebf\:4e0a\:7684\:4e24\:4e2a\:70b9\:53ef\:4ee5\:5224\:5b9a\:4e3a\:5728\:540c\:4e00\:6761\:7ebf\:4e0a\:ff0c\:4ee5\:4fbf\:5f00\:59cb\:4e00\:7b14\:753b\:ff0c\:6570\:8d8a\:5927\:ff0c\:7ebf\:6761\:6570\:5c31\:8d8a\:5c11\:ff0c\:901f\:5ea6\:4e00\:822c\:8d8a\:6162\:3002*)
  Print["\:7ebf\:6761\:6570\:ff1a", Length[hLines]];
  fCs = fourierComponents[hLines];
  Print[makeFourierSeriesApproximationManipulate[fCs, 100]];
  (*Print["\:6700\:7ec8\:8868\:8fbe\:5f0f\:ff1a"];
  finalCurve = 
   Rationalize[singleParametrization[fCs, t, terms] , 10^-order];
  Print[finalCurve // TraditionalForm];*)
  
  Print[ParametricPlot[Evaluate[N[finalCurve]], {t, 0, detail}, 
    PlotPoints -> points]];
  ]


f[pic,1, 2, 0.2, 2, 5, 200, 5, 128 Pi, 5000]
 
(*\:7b2c1\:4e2a\:53c2\:6570\:662f\:56fe\:7247\:5730\:5740\:ff1b
\:7b2c2\:4e2a\:53c2\:6570\:662f\:65b9\:6cd5\:7c7b\:522b\:ff0c\:65b9\:6cd51\:ff1a\:9ed8\:8ba4\:65b9\:6cd5\:ff0c\:81ea\:52a8\:65b9\:6cd5\:ff0c\:4e0d\:9700\:8981\:7b2c3,4\:4e2a\:53c2\:6570\:ff0c\:6548\:679c\:662f\:7b2c\:4e8c\:4e2a\:56fe\:ff0c\:65b9\:6cd52\:ff1a\:53ef\:4ee5\:624b\:52a8\:8c03\:6574\:8bc6\:522b\:7684\:8f6e\:5ed3\:ff0c\:6548\:679c\:662f\:7b2c\:4e09\:4e2a\:56fe\:ff1b
\:7b2c3\:4e2a\:53c2\:6570\:662f\:65b9\:6cd52\:4e2dEdgeDetect\:7684\:50cf\:7d20\:8303\:56f4\:ff0c\:9ed8\:8ba4\:662f2\:ff1b
\:7b2c4\:4e2a\:53c2\:6570\:662f\:9608\:503c\:ff0c\:9ed8\:8ba4\:662f0.2\:ff1b
\:7b2c5\:4e2a\:53c2\:6570\:662f\:968f\:673a\:6570\:9ed8\:8ba4\:662f2\:ff0c\:597d\:50cf\:8ddf\:8d77\:7b14\:70b9\:6709\:5173\:ff1b
\:7b2c6\:4e2a\:53c2\:6570\:63a7\:5236\:7740\:6709\:591a\:8fdc\:4e0d\:5728\:540c\:4e00\:6761\:7ebf\:4e0a\:7684\:4e24\:4e2a\:70b9\:53ef\:4ee5\:5224\:5b9a\:4e3a\:5728\:540c\:4e00\:6761\:7ebf\:4e0a\:ff0c\:4ee5\:4fbf\:5f00\:59cb\:4e00\:7b14\:753b\:ff0c\:6570\:8d8a\:5927\:ff0c\:7ebf\:6761\:6570\:5c31\:8d8a\:5c11\:ff0c\:901f\:5ea6\:4e00\:822c\:8d8a\:6162,\
\:6709\:4e9b\:60c5\:51b5\:7ebf\:6761\:8d8a\:591a\:8d8a\:597d\:ff0c\:6709\:4e9b\:9700\:8981\:5c3d\:91cf\:5c11\:3002
\:7b2c7\:4e2a\:53c2\:6570\:63a7\:5236\:7740Sin\:7684\:6570\:91cf\:ff0c\:6570\:5b57\:8d8a\:5927\:ff0c\:9879\:8d8a\:591a\:ff0c\:8868\:8fbe\:5f0f\:8d8a\:6076\:5fc3\:4f46\:662f\:8d8a\:7cbe\:786e\:3002
\:7b2c8\:4e2a\:53c2\:6570\:662f\:4e00\:4e2a\:9636\:6570\:ff0c\:5173\:7cfb\:7740\:628a\:7c7b\:4f3c\:7684Sin\:9879\:5408\:5e76\:ff0c\:6570\:8d8a\:5927\:ff0cSin\:9879\:8d8a\:591a\:ff0c\:56fe\:8d8a\:7cbe\:7ec6\:ff0c\:9ed8\:8ba4\:4e3a3\:3002
\:7b2c9\:4e2a\:53c2\:6570\:662f\:753b\:56fe\:7684\:8be6\:7ec6\:7a0b\:5ea6\:ff0c\:51fd\:6570\:53c2\:6570\:7684\:53d6\:503c\:8303\:56f4\:ff0c\:9ed8\:8ba464Pi\:3002
\:7b2c10\:4e2a\:53c2\:6570\:662f\:6700\:540e\:7ed3\:679c\:7528Mathematica\:7684\:63cf\:70b9\:6570\:ff0c\:9ed8\:8ba4100\:ff0c\:70b9\:8d8a\:591a\:8d8a\:7cbe\:786e\:4e5f\:8d8a\:6162\:ff0c\:6548\:679c\:662f\:6700\:540e\:4e00\:5f20\:56fe\:3002*)


Evaluate[N[finalCurve]]



