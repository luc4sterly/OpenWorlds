// 10042030 FUN_10042030 [Global]
// programa: RWL21.DLL

int FUN_10042030(int param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x6e);
  if (*(ushort *)(param_1 + 0x6c) == uVar1) {
    if (uVar1 == 0) {
      if (*(int *)(param_1 + 0x70) != 0) {
        FUN_1000cba0(100);
        return 0;
      }
      *(undefined2 *)(param_1 + 0x6c) = 0;
      *(undefined2 *)(param_1 + 0x6e) = 6;
      puVar2 = FUN_10037030(DAT_1005b8d0);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        return 0;
      }
    }
    else {
      uVar1 = (short)((uVar1 + 1) / 2) + uVar1;
      *(ushort *)(param_1 + 0x6e) = uVar1;
      if (uVar1 == 9) {
        puVar2 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x350))(4,9);
        if (puVar2 != (undefined4 *)0x0) {
          puVar4 = *(undefined4 **)(param_1 + 0x70);
          puVar5 = puVar2;
          for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        FUN_10037010(DAT_1005b8d0,*(undefined4 **)(param_1 + 0x70));
      }
      else {
        puVar2 = (undefined4 *)
                 (**(code **)(PTR_DAT_1005b69c + 0x354))
                           (*(undefined4 *)(param_1 + 0x70),(uint)uVar1 << 2);
      }
      if (puVar2 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        return 0;
      }
    }
    *(undefined4 **)(param_1 + 0x70) = puVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x70) + (uint)*(ushort *)(param_1 + 0x6c) * 4) = param_2;
  *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + 1;
  FUN_10041df0(param_1);
  FUN_10041ec0(param_1);
  return (-(uint)(*(short *)(param_1 + 0x6c) == 1) & 2) - 5;
}


