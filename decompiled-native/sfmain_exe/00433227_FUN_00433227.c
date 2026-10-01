// 00433227 FUN_00433227 [Global]
// program: sfmain.exe

undefined8 __fastcall
FUN_00433227(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  short local_c;
  
  local_c = (short)param_4;
  if ((param_4 >> 0x10 & 0x7ff0) == 0x7ff0) {
    puVar1 = param_5;
    if ((param_4 & 0x80000000) != 0) {
      puVar1 = (undefined4 *)((int)param_5 + 1);
      *(undefined1 *)param_5 = 0x2d;
    }
    uVar2 = DAT_00437bc0;
    if ((local_c == 0 && param_3 == 0) && (param_4 & 0xf0000) == 0) {
      uVar2 = DAT_00437bbc;
    }
    *puVar1 = uVar2;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}


