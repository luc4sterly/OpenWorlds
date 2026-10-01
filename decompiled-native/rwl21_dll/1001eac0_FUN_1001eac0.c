// 1001eac0 FUN_1001eac0 [Global]
// program: RWL21.DLL

undefined4 * FUN_1001eac0(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  piVar5 = (int *)&stack0xffffffc0;
  if (0 < param_2[2]) {
    while (0 < param_2[3]) {
      if (param_1 == (undefined4 *)0x0) {
        puVar4 = FUN_10037030(DAT_1005ac74);
        if (puVar4 == (undefined4 *)0x0) {
          FUN_1000cba0(3);
          return (undefined4 *)0x0;
        }
        *puVar4 = 0;
        puVar4[1] = *param_2;
        puVar4[2] = param_2[1];
        puVar4[3] = param_2[2];
        puVar4[4] = param_2[3];
        return puVar4;
      }
      iVar2 = FUN_1001e8a0(param_1 + 1,param_2);
      if (iVar2 == 1) {
        puVar4 = FUN_1001eac0((undefined4 *)*param_1,param_2);
        *param_1 = puVar4;
        return param_1;
      }
      if (iVar2 != 3) {
        if (iVar2 != 4) {
          return param_1;
        }
        piVar1 = param_1 + 1;
        uVar3 = FUN_1001e930(piVar1,param_2,&local_30);
        if (uVar3 == 3) {
          FUN_1001e930(param_2,piVar1,&local_30);
          *piVar1 = local_30;
          param_1[2] = local_2c;
          param_1[3] = local_28;
          param_1[4] = local_24;
          puVar4 = FUN_1001eac0((undefined4 *)*param_1,param_2);
          *param_1 = puVar4;
          return param_1;
        }
        if ((int)uVar3 < 1) {
          return param_1;
        }
        do {
          piVar5 = piVar5 + 4;
          puVar4 = FUN_1001eac0((undefined4 *)*param_1,piVar5);
          uVar3 = uVar3 - 1;
          *param_1 = puVar4;
        } while (uVar3 != 0);
        return param_1;
      }
      puVar4 = (undefined4 *)*param_1;
      FUN_10037010(DAT_1005ac74,param_1);
      param_1 = puVar4;
      if (param_2[2] < 1) {
        return puVar4;
      }
    }
  }
  return param_1;
}


