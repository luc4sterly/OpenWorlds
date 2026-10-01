// 0043fc20 _Java_NET_worlds_scape_TextureSurface_nativeDestroyDC@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_TextureSurface_nativeDestroyDC_12
               (int *param_1,undefined4 param_2,HDC param_3)

{
  undefined4 uVar1;
  int iVar2;
  HGDIOBJ pvVar3;
  
                    /* 0x3fc20  305  _Java_NET_worlds_scape_TextureSurface_nativeDestroyDC@12 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s__oldObject_00477f20,&DAT_00477f1c);
  if (iVar2 == 0) {
    FUN_00402800(s_nTexSurface_00477ee0,0x8c);
  }
  pvVar3 = (HGDIOBJ)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
  pvVar3 = SelectObject(param_3,pvVar3);
  DeleteObject(pvVar3);
  DeleteDC(param_3);
  return;
}


