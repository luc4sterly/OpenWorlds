// 00433ba2 FUN_00433ba2 [Global]
// program: sfmain.exe

undefined8 __fastcall
FUN_00433ba2(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,int *param_5)

{
  undefined4 in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (((param_4 & 0x7fffffff) != 0) || (param_3 != 0)) {
    iVar1 = ((int)(param_4 >> 0x10 & 0x7ff0) >> 4) + -0x3fe;
  }
  *param_5 = iVar1;
  return CONCAT44(param_2,in_EAX);
}


