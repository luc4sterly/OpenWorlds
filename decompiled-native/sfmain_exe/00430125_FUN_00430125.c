// 00430125 FUN_00430125 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_00430125(undefined4 param_1,int *param_2)

{
  int *in_EAX;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((in_EAX[2] < param_2[2]) ||
     ((in_EAX[2] == param_2[2] &&
      ((in_EAX[1] < param_2[1] || ((in_EAX[1] == param_2[1] && (*in_EAX < *param_2)))))))) {
    uVar1 = 1;
  }
  return uVar1;
}


