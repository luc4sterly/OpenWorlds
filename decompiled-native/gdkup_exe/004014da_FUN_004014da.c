// 004014da FUN_004014da [Global]
// program: gdkup.exe

undefined4 __thiscall
FUN_004014da(void *this,undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            ushort param_5,int *param_6,undefined2 *param_7,undefined4 param_8,undefined4 *param_9)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  bVar1 = FUN_004018b4(this,&DAT_00409f58);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0x80020001;
  }
  if (param_2 != 0) {
    if (param_2 < 2) {
      if ((param_5 & 1) == 0) {
        return 0x80020003;
      }
      if (param_6[2] != 2) {
        return 0x8002000e;
      }
      if (*(short *)(*param_6 + 0x10) != 8) {
        *param_9 = 1;
        return 0x80020005;
      }
      uVar4 = *(undefined4 *)(*param_6 + 0x18);
      if (*(short *)*param_6 != 8) {
        *param_9 = 0;
        return 0x80020005;
      }
      uVar3 = *(undefined4 *)(*param_6 + 8);
      uVar2 = FUN_00401390();
      if (param_7 != (undefined2 *)0x0) {
        Ordinal_8(param_7,uVar3,uVar4);
        *param_7 = 2;
        param_7[4] = (short)uVar2;
      }
      return 0;
    }
    if (param_2 == 2) {
      if ((param_5 & 1) == 0) {
        return 0x80020003;
      }
      if (param_6[2] != 1) {
        return 0x8002000e;
      }
      if (*(short *)*param_6 != 8) {
        *param_9 = 0;
        return 0x80020005;
      }
      FUN_004013b6(extraout_ECX,*(byte **)(*param_6 + 8));
      return 0;
    }
  }
  return 0;
}


