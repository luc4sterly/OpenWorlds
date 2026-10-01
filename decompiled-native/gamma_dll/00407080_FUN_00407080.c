// 00407080 FUN_00407080 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_00407080(undefined4 *param_1,int *param_2,void *param_3,byte param_4,double param_5)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  int iStack_70;
  byte bStack_69;
  int *piStack_68;
  int aiStack_64 [2];
  int aiStack_5c [3];
  int iStack_50;
  uint uStack_4c;
  undefined1 uStack_45;
  undefined1 uStack_29;
  
  FUN_004049b0(param_3,aiStack_64);
  uStack_45 = DAT_004890b4;
  piVar2 = (int *)FUN_00404a00(aiStack_64);
  FUN_00404dc0(aiStack_64);
  FUN_004049b0(param_3,aiStack_5c);
  uStack_29 = DAT_004890b6;
  FUN_00406190(aiStack_5c);
  FUN_00404dc0(aiStack_5c);
  iStack_70 = 0;
  if ((param_5 < _DAT_0046d920) || ((*(ushort *)((int)param_3 + 0x30) & 0x800) == 0)) {
    if ((byte)(param_5 < _DAT_0046d920 |
              (byte)((ushort)((ushort)(NAN(param_5) || NAN(_DAT_0046d920)) << 10) >> 8)) == 1) {
      iStack_70 = 1;
      bStack_69 = (**(code **)(*piVar2 + 0x14))(0x2d);
      param_5 = -param_5;
    }
  }
  else {
    iStack_70 = 1;
    bStack_69 = (**(code **)(*piVar2 + 0x14))(0x2b);
  }
  FUN_00407570((int *)&piStack_68);
  iStack_50 = param_5._0_4_;
  uStack_4c = param_5._4_4_;
  if (((ulonglong)param_5 & 0x7ff0000000000000) == 0) {
    if ((((ulonglong)param_5 & 0xfffff00000000) == 0) && (param_5._0_4_ == 0)) {
      uVar3 = 3;
    }
    else {
      uVar3 = 5;
    }
  }
  else if ((param_5._4_4_ & 0x7ff00000) == 0x7ff00000) {
    if ((((ulonglong)param_5 & 0xfffff00000000) == 0) && (param_5._0_4_ == 0)) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 4;
  }
  if (uVar3 < 3) {
    FUN_00407620(param_3,param_5._0_4_,param_5._4_4_,(int *)&piStack_68);
  }
  else {
    uVar1 = *(ushort *)((int)param_3 + 0x30) & 0x104;
    if (uVar1 == 4) {
      FUN_00407fe0(param_3,param_5._0_4_,param_5._4_4_,(int *)&piStack_68);
    }
    else if (uVar1 == 0x100) {
      FUN_00407a70(param_3,param_5._0_4_,param_5._4_4_,(int *)&piStack_68);
    }
    else {
      FUN_00407790(param_3,param_5._0_4_,param_5._4_4_,(int *)&piStack_68);
    }
  }
  FUN_00403820(param_1,param_2,(int)param_3,param_4,&bStack_69,iStack_70,(byte *)piStack_68[3],
               *piStack_68);
  EnterCriticalSection((LPCRITICAL_SECTION)(piStack_68 + 4));
  if (piStack_68[2] == 0) {
    piStack_68[2] = 1;
  }
  piStack_68[2] = piStack_68[2] + -1;
  piVar2 = piStack_68;
  if (piStack_68[2] != 0) {
    piVar2 = (int *)0x0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(piStack_68 + 4));
  if (piVar2 != (int *)0x0) {
    piStack_68 = piVar2;
    FUN_0044e100((undefined4 *)piVar2[3]);
    DeleteCriticalSection((LPCRITICAL_SECTION)(piVar2 + 4));
    FUN_0044e100(piStack_68);
  }
  return param_1;
}


