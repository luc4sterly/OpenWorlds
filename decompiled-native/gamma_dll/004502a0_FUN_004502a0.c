// 004502a0 FUN_004502a0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_004502a0(void *this,uint param_1,undefined4 param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte local_24 [12];
  int local_18;
  undefined1 local_14 [4];
  
  if (0xc < param_1) {
    return 0xffffffff;
  }
  uVar5 = (**(code **)(**(int **)((int)this + 0x2c) + 4))
                    ((int)this + 0x28,&param_2,(int)&param_2 + 2,local_14,local_24,&local_18,
                     &local_18);
  switch(uVar5) {
  case 0:
    param_1 = local_18 - (int)local_24;
    break;
  case 1:
  case 2:
    return 0xffffffff;
  case 3:
    param_1 = 2;
    FUN_0044df50((undefined4 *)local_24,&param_2,2);
  }
  iVar8 = 0;
  if (0 < (int)param_1) {
    do {
      puVar3 = *(undefined4 **)((int)this + 0x24);
      bVar2 = local_24[iVar8];
      iVar6 = FUN_004553d0((int)puVar3,-1);
      if (iVar6 < 0) {
        piVar1 = puVar3 + 0xb;
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar6 == 0) {
          uVar7 = FUN_00455650((int)(char)bVar2,puVar3);
        }
        else {
          pbVar4 = (byte *)puVar3[10];
          puVar3[10] = puVar3[10] + 1;
          *pbVar4 = bVar2;
          uVar7 = (uint)*pbVar4;
        }
      }
      else {
        uVar7 = 0xffffffff;
      }
      if (uVar7 == 0xffffffff) {
        return 0xffffffff;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)param_1);
  }
  return param_2;
}


