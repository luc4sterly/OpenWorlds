// 00440770 FUN_00440770 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00440770(void *this,LPCSTR param_1)

{
  HRESULT HVar1;
  int iVar2;
  int *local_218;
  WCHAR local_214 [260];
  
  local_218 = (int *)0x0;
  MultiByteToWideChar(0,0,param_1,-1,local_214,0x104);
  HVar1 = CoCreateInstance((IID *)&DAT_00467158,(LPUNKNOWN)0x0,1,(IID *)&DAT_00467168,&local_218);
  if (HVar1 < 0) {
    FUN_0044d5a0(s_Could_not_create_a_CLSID_MultiMe_004781b4);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(*local_218 + 0x30))(local_218,0,0,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_Initialize_failed__00478210);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(*local_218 + 0x3c))
                    (local_218,*(undefined4 *)((int)this + 0x14),&DAT_004671c8,0,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_AddMediaStream_failed__00478224);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(*local_218 + 0x3c))(local_218,0,&DAT_004671b8,1,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_AddMediaStream_failed__00478224);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  iVar2 = (**(code **)(*local_218 + 0x40))(local_218,local_214,0);
  if (iVar2 < 0) {
    FUN_0044d5a0(s_File_format_not_supported__0047823c);
    FUN_0044d5a0(&DAT_004780c8);
    return 0x80004005;
  }
  *(int **)((int)this + 0x24) = local_218;
  (**(code **)(*local_218 + 4))(local_218);
  return 0;
}


