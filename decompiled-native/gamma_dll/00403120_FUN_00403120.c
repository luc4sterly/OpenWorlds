// 00403120 FUN_00403120 [Global]
// programa: gamma.dll

int __cdecl FUN_00403120(int *param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar1,param_3,param_4);
  if (iVar2 == 0) {
    if (param_3 == s_No_such_java_method_0046d448) {
      pbVar6 = &DAT_0046d340;
      param_3 = s_No_such_java_method_0046d448;
      puVar4 = &DAT_0049eda8;
    }
    else {
      pbVar6 = &DAT_0046d340;
      pbVar5 = &DAT_0046d344;
      iVar3 = FUN_00403350(0x49eda8,(byte *)s_No_such_java_method_0046d448);
      puVar4 = (undefined *)FUN_00403350(iVar3,pbVar5);
    }
    iVar3 = FUN_00403350((int)puVar4,(byte *)param_3);
    FUN_00403350(iVar3,pbVar6);
    MessageBoxA((HWND)0x0,s_No_such_java_method_0046d448,s_Internal_Program_Error_0046d348,0x30);
    FUN_00450a90(0x29);
  }
  return iVar2;
}


