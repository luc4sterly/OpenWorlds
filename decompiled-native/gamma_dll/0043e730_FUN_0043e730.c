// 0043e730 FUN_0043e730 [Global]
// program: gamma.dll

void __fastcall FUN_0043e730(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_14;
  int *local_10;
  
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00466fe8,&local_14);
  if (-1 < iVar2) {
    (**(code **)(*local_14 + 0x18))(local_14,1);
    (**(code **)(*local_14 + 0xc))(local_14,0);
    (**(code **)(*local_14 + 8))(local_14);
  }
  iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x24))
                    (*(undefined4 **)(param_1 + 0x24),&DAT_00466fa8,&local_10);
  if (-1 < iVar2) {
    (**(code **)(*local_10 + 0x18))(local_10);
    (**(code **)(*local_10 + 0x14))(local_10);
    (**(code **)(*local_10 + 8))(local_10);
  }
  (**(code **)(**(int **)(param_1 + 0x24) + 8))(*(int **)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


