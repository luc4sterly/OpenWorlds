// 004028c0 FUN_004028c0 [Global]
// program: gamma.dll

void __cdecl FUN_004028c0(byte *param_1,byte *param_2)

{
  int iVar1;
  undefined *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (param_1 == param_2) {
    pbVar4 = &DAT_0046d340;
    puVar2 = &DAT_0049eda8;
    param_2 = param_1;
  }
  else {
    pbVar4 = &DAT_0046d340;
    pbVar3 = &DAT_0046d344;
    iVar1 = FUN_00403350(0x49eda8,param_1);
    puVar2 = (undefined *)FUN_00403350(iVar1,pbVar3);
  }
  iVar1 = FUN_00403350((int)puVar2,param_2);
  FUN_00403350(iVar1,pbVar4);
  MessageBoxA((HWND)0x0,(LPCSTR)param_1,s_Internal_Program_Error_0046d348,0x30);
  FUN_00450a90(0x29);
  return;
}


