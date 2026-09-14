// 004031c0 FUN_004031c0 [Global]
// programa: gamma.dll

int __cdecl FUN_004031c0(int *param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  iVar1 = (**(code **)(*param_1 + 0x1c4))(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (param_3 == s_No_such_java_method_0046d448) {
      pbVar5 = &DAT_0046d340;
      param_3 = s_No_such_java_method_0046d448;
      puVar3 = &DAT_0049eda8;
    }
    else {
      pbVar5 = &DAT_0046d340;
      pbVar4 = &DAT_0046d344;
      iVar2 = FUN_00403350(0x49eda8,(byte *)s_No_such_java_method_0046d448);
      puVar3 = (undefined *)FUN_00403350(iVar2,pbVar4);
    }
    iVar2 = FUN_00403350((int)puVar3,(byte *)param_3);
    FUN_00403350(iVar2,pbVar5);
    MessageBoxA((HWND)0x0,s_No_such_java_method_0046d448,s_Internal_Program_Error_0046d348,0x30);
    FUN_00450a90(0x29);
  }
  return iVar1;
}


