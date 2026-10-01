// 1001c500 FUN_1001c500 [Global]
// program: RWL21.DLL

undefined4 __fastcall
FUN_1001c500(undefined4 param_1,undefined4 param_2,float *param_3,int param_4,int param_5)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 uVar1;
  undefined8 uVar2;
  float local_44 [16];
  undefined1 local_4;
  undefined1 local_3;
  
  if (param_5 == 1) {
    uVar2 = FUN_100510e0(param_4,param_2,(undefined4 *)param_4,param_3);
    return (int)uVar2;
  }
  if (param_5 != 2) {
    if (param_5 != 3) {
      FUN_1000cba0(2);
      return 0;
    }
    if (*(char *)(param_3 + 0x10) == '\0') {
      if (*(char *)(param_4 + 0x40) == '\0') {
        uVar2 = FUN_1005118c(param_4,param_2,param_3,(float *)param_4,local_44);
        uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),local_44);
        local_3 = 1;
        local_4 = 0;
        uVar1 = extraout_ECX_04;
      }
      else {
        uVar2 = FUN_100510e0(param_4,param_2,param_3,local_44);
        uVar1 = extraout_ECX_03;
      }
    }
    else {
      uVar2 = FUN_100510e0(param_4,param_2,(undefined4 *)param_4,local_44);
      uVar1 = extraout_ECX_02;
    }
    uVar2 = FUN_100510e0(uVar1,(int)((ulonglong)uVar2 >> 0x20),(undefined4 *)uVar2,param_3);
    return (int)uVar2;
  }
  if (*(char *)(param_4 + 0x40) == '\0') {
    if (*(char *)(param_3 + 0x10) == '\0') {
      uVar2 = FUN_1005118c(param_4,param_2,(float *)param_4,param_3,local_44);
      uVar2 = CONCAT44((int)((ulonglong)uVar2 >> 0x20),local_44);
      local_3 = 1;
      local_4 = 0;
      uVar1 = extraout_ECX_01;
    }
    else {
      uVar2 = FUN_100510e0(param_4,param_2,(undefined4 *)param_4,local_44);
      uVar1 = extraout_ECX_00;
    }
  }
  else {
    uVar2 = FUN_100510e0(param_4,param_2,param_3,local_44);
    uVar1 = extraout_ECX;
  }
  uVar2 = FUN_100510e0(uVar1,(int)((ulonglong)uVar2 >> 0x20),(undefined4 *)uVar2,param_3);
  return (int)uVar2;
}


