// 1000997a FUN_1000997a [Global]
// program: RWDL8D21.DLL

int FUN_1000997a(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  bool in_ZF;
  int iVar7;
  int iStack00000004;
  int iStack00000008;
  int iStack0000000c;
  int iStack00000010;
  int in_stack_00000018;
  int in_stack_0000001c;
  
  if (!in_ZF) {
    if (((*(uint *)(in_EAX + 0x40) & 2) != 0) && (*(code **)(DAT_10077da8 + 0x298) != (code *)0x0))
    {
      (**(code **)(DAT_10077da8 + 0x298))();
    }
    *(uint *)(in_stack_0000001c + 0x40) = *(uint *)(in_stack_0000001c + 0x40) | 1;
    if (*(int *)(in_stack_0000001c + 0x18) != 0) {
      if (in_stack_00000018 != 0) {
        if (((*(uint *)(in_stack_00000018 + 0x40) & 2) != 0) &&
           (*(code **)(DAT_10077da8 + 0x298) != (code *)0x0)) {
          (**(code **)(DAT_10077da8 + 0x298))(in_stack_00000018);
        }
        puVar5 = *(undefined4 **)(in_stack_00000018 + 0x18);
        *(uint *)(in_stack_00000018 + 0x40) = *(uint *)(in_stack_00000018 + 0x40) | 1;
        if (puVar5 != (undefined4 *)0x0) {
          if ((*(int *)(in_stack_00000018 + 0x1c) == *(int *)(in_stack_0000001c + 0x1c)) &&
             (iVar7 = *(int *)(in_stack_00000018 + 0x20),
             *(int *)(in_stack_0000001c + 0x20) == iVar7)) {
            pbVar3 = *(byte **)(in_stack_0000001c + 0x18);
            iVar1 = *(int *)(in_stack_0000001c + 0x24);
            if (iVar1 == 8) {
              iStack00000004 = 1;
            }
            else if ((iVar1 == 0x10) || (iVar1 == 0xf)) {
              iStack00000004 = 2;
            }
            else {
              iStack00000004 = 4 - (uint)(iVar1 == 0x18);
            }
            iStack0000000c =
                 *(int *)(in_stack_0000001c + 0x28) -
                 *(int *)(in_stack_0000001c + 0x1c) * iStack00000004;
            iVar2 = *(int *)(in_stack_00000018 + 0x24);
            if (iVar2 == 8) {
              iStack00000008 = 1;
            }
            else if ((iVar2 == 0x10) || (iVar2 == 0xf)) {
              iStack00000008 = 2;
            }
            else {
              iStack00000008 = 4 - (uint)(iVar2 == 0x18);
            }
            iStack00000010 =
                 *(int *)(in_stack_00000018 + 0x28) -
                 *(int *)(in_stack_00000018 + 0x1c) * iStack00000008;
            while (iVar7 != 0) {
              iVar7 = iVar7 + -1;
              iVar4 = *(int *)(in_stack_00000018 + 0x1c);
              while (iVar4 != 0) {
                iVar4 = iVar4 + -1;
                if (iVar1 == 8) {
                  bVar6 = *pbVar3 < 0x80;
                }
                else if ((iVar1 == 0x10) || (iVar1 == 0xf)) {
                  bVar6 = ((byte)*(undefined2 *)pbVar3 & 0x1f) < 0x10;
                }
                else if (iVar1 == 0x18) {
                  bVar6 = pbVar3[1] < 0x80;
                }
                else {
                  bVar6 = pbVar3[1] < 0x80;
                }
                if (bVar6) {
                  if (iVar2 == 8) {
                    *(undefined1 *)puVar5 = 0;
                  }
                  else if ((iVar2 == 0x10) || (iVar2 == 0xf)) {
                    *(undefined2 *)puVar5 = 0;
                  }
                  else if (iVar2 == 0x20) {
                    *puVar5 = 0;
                  }
                  else {
                    *(undefined1 *)puVar5 = 0;
                    *(undefined1 *)((int)puVar5 + 1) = 0;
                    *(undefined1 *)((int)puVar5 + 2) = 0;
                  }
                }
                pbVar3 = pbVar3 + iStack00000004;
                puVar5 = (undefined4 *)((int)puVar5 + iStack00000008);
              }
              pbVar3 = pbVar3 + iStack0000000c;
              puVar5 = (undefined4 *)((int)puVar5 + iStack00000010);
            }
            *(uint *)(in_stack_00000018 + 0x40) = *(uint *)(in_stack_00000018 + 0x40) | 1;
            if (((in_stack_0000001c != 0) && ((*(uint *)(in_stack_0000001c + 0x40) & 2) != 0)) &&
               (*(code **)(DAT_10077da8 + 0x29c) != (code *)0x0)) {
              (**(code **)(DAT_10077da8 + 0x29c))(in_stack_0000001c);
            }
            if (((in_stack_00000018 != 0) && ((*(uint *)(in_stack_00000018 + 0x40) & 2) != 0)) &&
               (*(code **)(DAT_10077da8 + 0x29c) != (code *)0x0)) {
              (**(code **)(DAT_10077da8 + 0x29c))(in_stack_00000018);
            }
            return in_stack_00000018;
          }
          if (((in_stack_0000001c != 0) && ((*(uint *)(in_stack_0000001c + 0x40) & 2) != 0)) &&
             (*(code **)(DAT_10077da8 + 0x29c) != (code *)0x0)) {
            (**(code **)(DAT_10077da8 + 0x29c))(in_stack_0000001c);
          }
          if (((in_stack_00000018 != 0) && ((*(uint *)(in_stack_00000018 + 0x40) & 2) != 0)) &&
             (*(code **)(DAT_10077da8 + 0x29c) != (code *)0x0)) {
            (**(code **)(DAT_10077da8 + 0x29c))(in_stack_00000018);
          }
          return 0;
        }
      }
      if (((in_stack_0000001c != 0) && ((*(uint *)(in_stack_0000001c + 0x40) & 2) != 0)) &&
         (*(code **)(DAT_10077da8 + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_10077da8 + 0x29c))(in_stack_0000001c);
      }
      return 0;
    }
  }
  return 0;
}


