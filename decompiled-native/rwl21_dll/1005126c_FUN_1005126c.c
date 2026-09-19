// 1005126c FUN_1005126c [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_1005126c(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,uint *param_5)

{
  longlong lVar1;
  undefined4 in_EAX;
  int *piVar2;
  
  _DAT_10061020 = 4;
  do {
    _DAT_1006101c = 4;
    do {
      piVar2 = param_4;
      lVar1 = (longlong)param_3[1] * (longlong)piVar2[4] + (longlong)*param_3 * (longlong)*piVar2 +
              (longlong)param_3[2] * (longlong)piVar2[8] +
              (longlong)param_3[3] * (longlong)piVar2[0xc];
      *param_5 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
      param_5 = param_5 + 1;
      _DAT_1006101c = _DAT_1006101c + -1;
      param_4 = piVar2 + 1;
    } while (_DAT_1006101c != 0);
    param_4 = piVar2 + -3;
    param_3 = param_3 + 4;
    _DAT_10061020 = _DAT_10061020 + -1;
  } while (_DAT_10061020 != 0);
  return CONCAT44(param_2,in_EAX);
}


