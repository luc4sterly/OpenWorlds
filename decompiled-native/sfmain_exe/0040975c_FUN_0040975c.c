// 0040975c FUN_0040975c [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040975c(undefined4 *param_1,int *param_2,int param_3,int *param_4)

{
  float fVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float local_24;
  float local_20;
  int local_1c [2];
  float local_14;
  int local_10;
  
  iVar4 = *param_2;
  local_14 = 0.7;
  if (0x9b < iVar4) {
    iVar4 = 0x9c;
  }
  if (iVar4 < 0x15) {
    iVar4 = 0x14;
  }
  else {
    iVar4 = *param_2;
    if (0x9b < iVar4) {
      iVar4 = 0x9c;
    }
  }
  pfVar5 = (float *)(param_1 + 1);
  *param_2 = iVar4;
  do {
    dVar2 = (double)*pfVar5;
    if ((float)_DAT_00435804 <= *pfVar5) {
      dVar2 = 0.99;
    }
    if (dVar2 <= _DAT_0043580c) {
      fVar1 = -0.99;
    }
    else {
      fVar1 = *pfVar5;
      if ((float)_DAT_00435804 <= fVar1) {
        fVar1 = 0.99;
      }
    }
    *pfVar5 = fVar1;
    pfVar5 = pfVar5 + 1;
  } while (pfVar5 != (float *)(param_1 + 0xb));
  *param_4 = 0;
  FUN_00409e0f(param_1,param_2,0x443360,0x443334,0x44338c,&DAT_004401f8,local_1c,&local_20);
  if (0 < local_1c[0]) {
    iVar7 = 0;
    local_10 = 0;
    iVar4 = extraout_ECX;
    while (local_10 < local_1c[0]) {
      FUN_0040adb7(iVar4,(float *)&DAT_004406c0,local_14,&local_24,local_10);
      FUN_0040c9ff(&DAT_0043fe88,*(int *)((int)&DAT_00443338 + iVar7),
                   *(float *)((int)&DAT_00443390 + iVar7),local_20,local_24);
      FUN_0040bf9f(extraout_ECX_00,*(int *)((int)&DAT_00443338 + iVar7));
      iVar4 = 4;
      for (iVar6 = 1; iVar6 <= *(int *)((int)&DAT_00443338 + iVar7); iVar6 = iVar6 + 1) {
        iVar3 = *param_4;
        *param_4 = iVar3 + 1;
        pfVar5 = (float *)(&DAT_0043fe84 + iVar4);
        iVar4 = iVar4 + 4;
        *(float *)((iVar3 + 1) * 4 + param_3) = *pfVar5 * (float)_DAT_004357fc;
      }
      iVar7 = iVar7 + 4;
      iVar4 = local_10 + 1;
      local_10 = iVar4;
    }
  }
  return;
}


