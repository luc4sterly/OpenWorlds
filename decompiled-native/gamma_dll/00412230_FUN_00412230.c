// 00412230 FUN_00412230 [Global]
// program: gamma.dll

uint __thiscall FUN_00412230(void *this,uint param_1,char param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte local_28 [15];
  byte local_19;
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  
  if (0xc < param_1) {
    return 0xffffffff;
  }
  iVar7 = 0;
  if (0 < (int)param_1) {
    do {
      puVar2 = *(undefined4 **)((int)this + 0x24);
      iVar5 = FUN_004553d0((int)puVar2,-1);
      if (iVar5 < 0) {
        piVar1 = puVar2 + 0xb;
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        if (iVar5 == 0) {
          uVar6 = FUN_00455440(puVar2);
        }
        else {
          pbVar3 = (byte *)puVar2[10];
          puVar2[10] = puVar2[10] + 1;
          uVar6 = (uint)*pbVar3;
        }
      }
      else {
        uVar6 = 0xffffffff;
      }
      if (uVar6 == 0xffffffff) {
        return 0xffffffff;
      }
      local_28[iVar7] = (byte)uVar6;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)param_1);
  }
  uVar4 = (**(code **)(**(int **)((int)this + 0x2c) + 8))
                    ((int)this + 0x28,local_28,local_28 + param_1,local_18,&local_19,local_18,
                     local_14);
  switch(uVar4) {
  case 1:
  case 2:
    return 0xffffffff;
  case 3:
    local_19 = local_28[0];
  }
  if (param_2 != '\0') {
    while (0 < (int)param_1) {
      uVar6 = FUN_004555b0((int)(char)(&stack0xffffffd7)[param_1],*(int *)((int)this + 0x24));
      param_1 = param_1 - 1;
      if (uVar6 == 0xffffffff) {
        return 0xffffffff;
      }
    }
  }
  return (uint)local_19;
}


