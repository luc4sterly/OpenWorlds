// 00445e70 FUN_00445e70 [Global]
// program: gamma.dll

int FUN_00445e70(int *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_18;
  uint local_14;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  puVar1 = (undefined4 *)*param_1;
  iVar5 = (**(code **)(*param_2 + 0x1c))(param_2,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  if (param_3 != 0) {
    puVar1 = (undefined4 *)*param_1;
    iVar5 = (**(code **)(*param_2 + 0xc))
                      (param_2,*puVar1,puVar1[1],puVar1[2],puVar1[3],param_1[1],param_1[2]);
    if (-1 < iVar5) {
      local_18 = 0;
      for (local_14 = 0; local_14 < (uint)param_1[3]; local_14 = local_14 + 1) {
        iVar5 = param_1[4];
        puVar1 = *(undefined4 **)(iVar5 + 0x14 + local_18);
        puVar2 = (undefined4 *)*param_1;
        iVar5 = (**(code **)(*param_2 + 0x14))
                          (param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3],
                           *(undefined4 *)(iVar5 + local_18),*(undefined4 *)(iVar5 + 4 + local_18),
                           *(undefined4 *)(iVar5 + 8 + local_18),
                           *(undefined4 *)(iVar5 + 0xc + local_18),
                           *(undefined4 *)(iVar5 + 0x10 + local_18),*puVar1,puVar1[1],puVar1[2],
                           puVar1[3],*(undefined4 *)(iVar5 + 0x18 + local_18));
        if (-1 < iVar5) {
          for (uVar6 = 0; iVar4 = param_1[4], uVar6 < *(uint *)(iVar4 + 0x1c + local_18);
              uVar6 = uVar6 + 1) {
            iVar5 = *(int *)(iVar4 + 0x20 + local_18);
            puVar1 = *(undefined4 **)(iVar5 + uVar6 * 8);
            puVar2 = *(undefined4 **)(iVar5 + 4 + uVar6 * 8);
            puVar3 = (undefined4 *)*param_1;
            iVar5 = (**(code **)(*param_2 + 0x18))
                              (param_2,*puVar3,puVar3[1],puVar3[2],puVar3[3],
                               *(undefined4 *)(iVar4 + local_18),*puVar1,puVar1[1],puVar1[2],
                               puVar1[3],*puVar2,puVar2[1],puVar2[2],puVar2[3]);
            if (iVar5 < 0) break;
          }
          if (iVar5 < 0) break;
        }
        if (iVar5 < 0) break;
        local_18 = local_18 + 0x24;
      }
    }
  }
  if (iVar5 == -0x7ff8fffe) {
    return 0;
  }
  return iVar5;
}


