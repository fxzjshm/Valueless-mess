VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6690
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9480
   LinkTopic       =   "Form1"
   MouseIcon       =   "Form1.frx":0000
   ScaleHeight     =   6690
   ScaleWidth      =   9480
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command1 
      Caption         =   "普通模式"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   5640
      Width           =   2415
   End
   Begin VB.CommandButton Command3 
      Caption         =   "暴打模式"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   6720
      TabIndex        =   1
      Top             =   5640
      Width           =   2415
   End
   Begin VB.CommandButton Command2 
      Caption         =   "无尽模式"
      BeginProperty Font 
         Name            =   "楷体_GB2312"
         Size            =   21.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   3480
      TabIndex        =   0
      Top             =   5640
      Width           =   2415
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "伏地魔：我好怕怕~~"
      BeginProperty Font 
         Name            =   "黑体"
         Size            =   18
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2520
      TabIndex        =   5
      Top             =   4560
      Width           =   3735
   End
   Begin VB.Image Image2 
      Height          =   2220
      Left            =   2520
      Picture         =   "Form1.frx":18E12
      Top             =   2280
      Width           =   3750
   End
   Begin VB.Shape Shape1 
      BorderStyle     =   0  'Transparent
      Height          =   2415
      Left            =   1680
      Top             =   2160
      Width           =   4455
   End
   Begin VB.Label Label2 
      BackStyle       =   0  'Transparent
      Height          =   1935
      Left            =   120
      TabIndex        =   4
      Top             =   720
      Width           =   375
   End
   Begin VB.Label Label1 
      BackColor       =   &H00FFFFFF&
      BackStyle       =   0  'Transparent
      Caption         =   " Kill Voldemort   暴打伏地魔"
      BeginProperty Font 
         Name            =   "Harry P"
         Size            =   48
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1935
      Left            =   2040
      TabIndex        =   3
      Top             =   360
      Width           =   5295
   End
   Begin VB.Image Image1 
      Height          =   7665
      Left            =   0
      Picture         =   "Form1.frx":1A405
      Top             =   -960
      Width           =   9450
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form2.Show
Unload Me
End Sub
Private Sub Command2_Click()
Form3.Show
Unload Me
End Sub
Private Sub Command3_Click()
Form4.Show
Unload Me
End Sub
Private Sub Image2_Click()
Timer1.Enabled = True
End Sub
