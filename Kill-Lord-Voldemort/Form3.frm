VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   6690
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9480
   LinkTopic       =   "Form3"
   ScaleHeight     =   6690
   ScaleWidth      =   9480
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command1 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   1440
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   3240
      Width           =   1335
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   0
      Top             =   0
   End
   Begin VB.CommandButton Command2 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   4080
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":0817
      Style           =   1  'Graphical
      TabIndex        =   4
      Top             =   3240
      Width           =   1335
   End
   Begin VB.CommandButton Command3 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   6840
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":102E
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   3240
      Width           =   1335
   End
   Begin VB.CommandButton Command4 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   1440
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":1845
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   5400
      Width           =   1335
   End
   Begin VB.CommandButton Command5 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   4080
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":205C
      Style           =   1  'Graphical
      TabIndex        =   1
      Top             =   5400
      Width           =   1335
   End
   Begin VB.CommandButton Command6 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   6840
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form3.frx":2873
      Style           =   1  'Graphical
      TabIndex        =   0
      Top             =   5400
      Width           =   1335
   End
   Begin VB.Timer Timer2 
      Enabled         =   0   'False
      Interval        =   1500
      Left            =   360
      Top             =   0
   End
   Begin VB.Timer Timer3 
      Interval        =   100
      Left            =   720
      Top             =   0
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   0
      TabIndex        =   13
      Top             =   840
      Width           =   3615
   End
   Begin VB.Image Image9 
      Height          =   1680
      Left            =   3600
      Picture         =   "Form3.frx":308A
      Top             =   0
      Width           =   1320
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "：快快点击伏地魔，与我一起主持正义吧！！！！！"
      BeginProperty Font 
         Name            =   "黑体"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   4920
      TabIndex        =   12
      Top             =   120
      Width           =   4455
   End
   Begin VB.Image Image13 
      Height          =   1020
      Left            =   4440
      Picture         =   "Form3.frx":3EA8
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image14 
      Height          =   960
      Left            =   4440
      Picture         =   "Form3.frx":4806
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image15 
      Height          =   1020
      Left            =   7200
      Picture         =   "Form3.frx":5412
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image16 
      Height          =   960
      Left            =   7200
      Picture         =   "Form3.frx":5D70
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image17 
      Height          =   1020
      Left            =   1800
      Picture         =   "Form3.frx":697C
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image18 
      Height          =   960
      Left            =   1800
      Picture         =   "Form3.frx":72DA
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image19 
      Height          =   1020
      Left            =   4440
      Picture         =   "Form3.frx":7EE6
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image20 
      Height          =   960
      Left            =   4440
      Picture         =   "Form3.frx":8844
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image21 
      Height          =   1020
      Left            =   7200
      Picture         =   "Form3.frx":9450
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image22 
      Height          =   960
      Left            =   7200
      Picture         =   "Form3.frx":9DAE
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image11 
      Height          =   1020
      Left            =   1800
      Picture         =   "Form3.frx":A9BA
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image10 
      Height          =   960
      Left            =   1800
      Picture         =   "Form3.frx":B318
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "黑体"
         Size            =   18
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   5040
      TabIndex        =   11
      Top             =   960
      Width           =   4215
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   " "
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   72
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   3480
      TabIndex        =   10
      Top             =   960
      Width           =   2535
   End
   Begin VB.Image Image2 
      Height          =   945
      Left            =   1800
      Picture         =   "Form3.frx":BF24
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image3 
      Height          =   945
      Left            =   4440
      Picture         =   "Form3.frx":CFF8
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image4 
      Height          =   945
      Left            =   7200
      Picture         =   "Form3.frx":E0CC
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image5 
      Height          =   945
      Left            =   1800
      Picture         =   "Form3.frx":F1A0
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image6 
      Height          =   945
      Left            =   4440
      Picture         =   "Form3.frx":10274
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image7 
      Height          =   945
      Left            =   7200
      Picture         =   "Form3.frx":11348
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   0
      TabIndex        =   9
      Top             =   1560
      Width           =   4455
   End
   Begin VB.Label Label6 
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      Height          =   495
      Left            =   0
      TabIndex        =   8
      Top             =   6240
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.Label Label7 
      BackStyle       =   0  'Transparent
      Caption         =   "3"
      Height          =   495
      Left            =   600
      TabIndex        =   7
      Top             =   6240
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label8 
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      Height          =   495
      Left            =   0
      TabIndex        =   6
      Top             =   5760
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.Image Image1 
      Height          =   7665
      Left            =   0
      Picture         =   "Form3.frx":1241C
      Top             =   0
      Width           =   9450
   End
   Begin VB.Image Image8 
      Height          =   1515
      Left            =   0
      Picture         =   "Form3.frx":2174C
      Top             =   0
      Width           =   3585
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
