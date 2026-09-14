// 00416b00 FUN_00416b00 [Global]
// programa: gamma.dll

undefined1 __thiscall FUN_00416b00(void *this,int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_14;
  
  local_14 = 0;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x14));
  do {
    if (*(int *)((int)this + 0x10) == 0) {
LAB_00416c3d:
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x14));
      return local_14;
    }
    puVar4 = (undefined4 *)(*(int *)((int)this + 8) * 0x14 + *(int *)((int)this + 4));
    (**(code **)(*param_1 + 0x1ac))(param_1,param_2,DAT_0048950c,*(undefined2 *)puVar4);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489510,puVar4[1]);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489514,puVar4[2]);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489518,puVar4[3]);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0048951c,puVar4[4]);
    *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
    if (*(int *)((int)this + 8) == *(int *)this) {
      *(undefined4 *)((int)this + 8) = 0;
    }
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + -1;
    puVar1 = (undefined4 *)*puVar4;
    if (puVar4[1] != 10) {
      local_14 = 1;
      goto LAB_00416c3d;
    }
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_TeleportAction_0047008c);
    uVar3 = (**(code **)(*param_1 + 0x1c4))
                      (param_1,uVar2,s_teleport_004700e4,s__Ljava_lang_String_LNET_worlds_s_004700ac
                      );
    (**(code **)(*param_1 + 0x29c))(param_1,puVar1);
    FUN_00402bd0(param_1,uVar2,uVar3);
    FUN_00451780(puVar1);
  } while( true );
}


