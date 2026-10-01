// 1000262b FUN_1000262b [Global]
// program: RWDL8D21.DLL

undefined4 FUN_1000262b(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool in_ZF;
  int iStack00000004;
  int iStack00000008;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  puVar8 = (undefined4 *)0xdead;
  if ((!in_ZF) &&
     (((in_stack_00000014 * 2 - DAT_10077eb0 != 0 && DAT_10077eb0 <= in_stack_00000014 * 2 ||
       (DAT_10077da0 < in_stack_00000018)) &&
      (iVar1 = FUN_100087b0(in_stack_00000014,in_stack_00000018), iVar1 == 0)))) {
    return 0;
  }
  *(uint *)(*(int *)(in_stack_00000010 + 0x104) + 0x40) =
       *(uint *)(*(int *)(in_stack_00000010 + 0x104) + 0x40) | 2;
  *(int *)(*(int *)(in_stack_00000010 + 0x104) + 0x1c) = in_stack_00000014;
  *(int *)(*(int *)(in_stack_00000010 + 0x104) + 0x20) = in_stack_00000018;
  *(int *)(*(int *)(in_stack_00000010 + 0x104) + 0x28) = DAT_10077eb0;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 0x24) = DAT_100750ec;
  **(undefined4 **)(in_stack_00000010 + 0x104) = 4;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 4) = DAT_100750ec;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 8) = 0;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 0xc) = 0;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 0x10) = 0;
  *(undefined4 *)(*(int *)(in_stack_00000010 + 0x104) + 0x14) = 0;
  iVar1 = (**(code **)(DAT_10077da8 + 0x34c))(in_stack_00000018 << 2);
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(in_stack_00000010 + 0x220) = iVar1;
  if (*(int *)(in_stack_00000010 + 0x10c) != 0) {
    uVar7 = in_stack_00000014 + 3U & 0xfffffffc;
    puVar2 = (undefined4 *)(**(code **)(DAT_10077da8 + 0x34c))(0x28);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0xffffffff;
    puVar2[6] = 0xffffffff;
    puVar2[7] = 0;
    puVar2[8] = 0;
    iStack00000008 = (int)(DAT_10075064 * uVar7 + ((int)(DAT_10075064 * uVar7) >> 0x1f & 7U)) >> 3;
    iStack00000004 = in_stack_00000018 * iStack00000008;
    if (*(int *)(in_stack_00000010 + 0x10c) != 0) {
      if (DAT_1007505c == 0) {
        iVar3 = iStack00000004 + 0x28;
      }
      else {
        iVar3 = iStack00000004 + 0x428;
      }
      puVar8 = (undefined4 *)(**(code **)(DAT_10077da8 + 0x34c))(iVar3);
      if (puVar8 == (undefined4 *)0x0) {
        (**(code **)(DAT_10077da8 + 0x358))(iVar1);
        (**(code **)(DAT_10077da8 + 0x358))(puVar2);
        return 0;
      }
      if (DAT_1007505c == 0) {
        puVar4 = (undefined4 *)0x0;
        puVar5 = puVar8 + 10;
      }
      else {
        puVar5 = puVar8 + 0x10a;
        puVar4 = puVar8 + 10;
      }
      *puVar8 = 0x28;
      puVar8[1] = uVar7;
      puVar8[2] = in_stack_00000018;
      *(undefined2 *)(puVar8 + 3) = 1;
      *(short *)((int)puVar8 + 0xe) = (short)DAT_10075064;
      puVar8[4] = 0;
      puVar8[5] = iStack00000004;
      puVar8[6] = 1;
      puVar8[7] = 1;
      if (DAT_1007505c == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0x100;
      }
      puVar8[8] = uVar6;
      puVar8[9] = uVar6;
      if (DAT_1007505c != 0) {
        if (DAT_10075058 == 0) {
          puVar4 = puVar4 + 10;
          iVar1 = 10;
          do {
            iVar3 = iVar1 + 1;
            *(undefined1 *)puVar4 = *(undefined1 *)((int)&DAT_10077db0 + iVar1);
            *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)&DAT_10077fc0 + iVar1);
            *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)&DAT_10077ec0 + iVar1);
            *(undefined1 *)((int)puVar4 + 3) = 0;
            puVar4 = puVar4 + 1;
            iVar1 = iVar3;
          } while (iVar3 < 0xf6);
        }
        else {
          iVar1 = 0;
          do {
            *(short *)((int)puVar4 + iVar1 * 2) = (short)iVar1;
            iVar1 = iVar1 + 1;
          } while (iVar1 < 0x100);
        }
      }
      puVar2[1] = puVar5;
      puVar2[2] = puVar8;
      puVar4 = *(undefined4 **)(in_stack_00000010 + 0x100);
      puVar4[6] = (undefined4 *)((in_stack_00000018 + -1) * iStack00000008 + (int)puVar5);
      puVar4[7] = uVar7;
      puVar4[10] = -iStack00000008;
      puVar4[8] = in_stack_00000018;
      puVar4[9] = DAT_10075064;
      puVar4[0x10] = puVar4[0x10] | 2;
      iVar1 = DAT_10075064;
      puVar4[1] = DAT_10075064;
      if (iVar1 == 8) {
        *puVar4 = 1;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
      }
      puVar4[0xb] = puVar2;
    }
    *(undefined4 **)(in_stack_00000010 + 0x108) = puVar8;
    return 1;
  }
  *(uint *)(in_stack_00000010 + 0x228) = *(uint *)(in_stack_00000010 + 0x228) | 2;
  return 1;
}


