/* WARNING: This is a generated file.
 * Any manual changes will be overwritten.

 */
#include "nodeset_lifeCycleEntry.h"
UA_INLINE UA_StatusCode nodeset(UA_Server *server){
  return nodeset_returnNamespaces(server, NULL, NULL);
}

UA_INLINE UA_StatusCode nodeset_returnNamespaces(
        UA_Server *server, UA_UInt16 *namespacesSize, UA_Namespace **namespaces) {
  UA_StatusCode retval = UA_STATUSCODE_GOOD;
  UA_Namespace* nsArray = UA_malloc(2 * sizeof(UA_Namespace));
  UA_String tempNsUri;

  //Adding namespace for old namespace index = 0 with uri: http://opcfoundation.org/UA/
  tempNsUri = UA_String_fromChars("http://opcfoundation.org/UA/");
  UA_Namespace_init(&nsArray[0], &tempNsUri);
  UA_String_deleteMembers(&tempNsUri);
  retval |= UA_Server_addNamespace_full(server, &nsArray[0]);
  UA_UInt16 nsIdx_0 = nsArray[0].index;
  //Adding namespace for old namespace index = 2 with uri: http://acplt.org/lifeCycleEntry/
  tempNsUri = UA_String_fromChars("http://acplt.org/lifeCycleEntry/");
  UA_Namespace_init(&nsArray[1], &tempNsUri);
  UA_String_deleteMembers(&tempNsUri);
  retval |= UA_Server_addNamespace_full(server, &nsArray[1]);
  UA_UInt16 nsIdx_2 = nsArray[1].index;

  //Writing back desired namespace values')
  if(namespacesSize) {*namespacesSize = 2;};
  if(namespaces) {namespaces = &nsArray;}
  else {
    for(size_t i = 0 ; i < 2 ; ++i){
      UA_Namespace_deleteMembers(&nsArray[i]);
    }
    UA_free(nsArray);
  }
  if(retval == UA_STATUSCODE_GOOD){retval = UA_STATUSCODE_GOOD;} //ensure that retval is used
  

do {
// Referencing node found and declared as parent: i=22/Structure using i=45/HasSubtype
// Node: opcua_node_dataType_t(ns=2;i=3002), 1:LifeCycleEntry
UA_DataTypeAttributes attr;
UA_DataTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "LifeCycleEntry");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 3002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_0, 22);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "LifeCycleEntry");
UA_Server_addDataTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);
/*
do {
// Referencing node found and declared as parent: i=93/OPC Binary using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6001), 1:TypeDictionary
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "TypeDictionary");
attr.description = UA_LOCALIZEDTEXT("", "Collects the data type descriptions of http://acplt.org/lifeCycleEntry/");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_ByteString *opcua_node_variable_t_ns_2_i_6001_variant_DataContents =  UA_ByteString_new();
*opcua_node_variable_t_ns_2_i_6001_variant_DataContents = UA_STRING_ALLOC("PG9wYzpUeXBlRGljdGlvbmFyeSB4bWxuczp4c2k9Imh0dHA6Ly93d3cudzMub3JnLzIwMDEvWE1MU2NoZ        W1hLWluc3RhbmNlIiB4bWxuczp0bnM9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0aW9uLm9yZy9sY        2UvIiBEZWZhdWx0Qnl0ZU9yZGVyPSJMaXR0bGVFbmRpYW4iIHhtbG5zOm9wYz0iaHR0cDovL        29wY2ZvdW5kYXRpb24ub3JnL0JpbmFyeVNjaGVtYS8iIHhtbG5zOm5zMT0iaHR0cDovL3lvd        XJvcmdhbmlzYXRpb24ub3JnL2lkZW50aWZpY2F0aW9uLyIgeG1sbnM6dWE9Imh0dHA6Ly9vc        GNmb3VuZGF0aW9uLm9yZy9VQS8iIFRhcmdldE5hbWVzcGFjZT0iaHR0cDovL3lvdXJvcmdhb        mlzYXRpb24ub3JnL2xjZS8iPgogPG9wYzpJbXBvcnQgTmFtZXNwYWNlPSJodHRwOi8vb3BjZ        m91bmRhdGlvbi5vcmcvVUEvIi8+CiA8b3BjOlN0cnVjdHVyZWRUeXBlIEJhc2VUeXBlPSJ1Y        TpFeHRlbnNpb25PYmplY3QiIE5hbWU9IkxpZmVDeWNsZUVudHJ5Ij4KICA8b3BjOkZpZWxkI        FR5cGVOYW1lPSJuczE6SWRlbnRpZmljYXRpb24iIE5hbWU9IkNyZWF0aW5nSW5zdGFuY2UiL        z4KICA8b3BjOkZpZWxkIFR5cGVOYW1lPSJuczE6SWRlbnRpZmljYXRpb24iIE5hbWU9Ildya        XRpbmdJbnN0YW5jZSIvPgogIDxvcGM6RmllbGQgVHlwZU5hbWU9InVhOkRhdGFWYWx1ZSIgT        mFtZT0iRGF0YSIvPgogIDxvcGM6RmllbGQgVHlwZU5hbWU9Im9wYzpDaGFyQXJyYXkiIE5hb        WU9IlN1YmplY3QiLz4KICA8b3BjOkZpZWxkIFR5cGVOYW1lPSJvcGM6Q2hhckFycmF5IiBOY        W1lPSJFdmVudENsYXNzIi8+CiAgPG9wYzpGaWVsZCBUeXBlTmFtZT0ib3BjOkludDY0IiBOY        W1lPSJJZCIvPgogPC9vcGM6U3RydWN0dXJlZFR5cGU+CiA8b3BjOmltcG9ydCBOYW1lc3BhY        2U9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0aW9uLm9yZy9pZGVudGlmaWNhdGlvbi8iLz4KPC9vc        GM6VHlwZURpY3Rpb25hcnk+Cg==");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6001_variant_DataContents, &UA_TYPES[UA_TYPES_BYTESTRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6001);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 72);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_0, 93);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "TypeDictionary");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6001), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 72), true);
} while(0);
*/
do {
// Referencing node found and declared as parent: ns=2;i=6001/1:TypeDictionary using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6005), 1:LifeCycleEntry
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "LifeCycleEntry");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6005_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6005_variant_DataContents = UA_STRING_ALLOC("LifeCycleEntry");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6005_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6005);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 69);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_2, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "LifeCycleEntry");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6005), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 69), true);
} while(0);

do {
// Referencing node found and declared as parent: i=92/XML Schema using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6003), 1:TypeDictionary
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "TypeDictionary");
attr.description = UA_LOCALIZEDTEXT("", "Collects the data type descriptions of http://acplt.org/lifeCycleEntry/");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_ByteString *opcua_node_variable_t_ns_2_i_6003_variant_DataContents =  UA_ByteString_new();
*opcua_node_variable_t_ns_2_i_6003_variant_DataContents = UA_STRING_ALLOC("PHhzOnNjaGVtYSBlbGVtZW50Rm9ybURlZmF1bHQ9InF1YWxpZmllZCIgdGFyZ2V0TmFtZXNwYWNlPSJod        HRwOi8veW91cm9yZ2FuaXNhdGlvbi5vcmcvbGNlL1R5cGVzLnhzZCIgeG1sbnM6dG5zPSJod        HRwOi8veW91cm9yZ2FuaXNhdGlvbi5vcmcvbGNlL1R5cGVzLnhzZCIgeG1sbnM6bnMxPSJod        HRwOi8veW91cm9yZ2FuaXNhdGlvbi5vcmcvaWRlbnRpZmljYXRpb24vVHlwZXMueHNkIiB4b        Wxuczp1YT0iaHR0cDovL29wY2ZvdW5kYXRpb24ub3JnL1VBLzIwMDgvMDIvVHlwZXMueHNkI        iB4bWxuczp4cz0iaHR0cDovL3d3dy53My5vcmcvMjAwMS9YTUxTY2hlbWEiPgogPHhzOmltc        G9ydCBuYW1lc3BhY2U9Imh0dHA6Ly9vcGNmb3VuZGF0aW9uLm9yZy9VQS8yMDA4LzAyL1R5c        GVzLnhzZCIvPgogPHhzOmltcG9ydCBuYW1lc3BhY2U9Imh0dHA6Ly95b3Vyb3JnYW5pc2F0a        W9uLm9yZy9pZGVudGlmaWNhdGlvbi9UeXBlcy54c2QiLz4KIDx4czpjb21wbGV4VHlwZSBuY        W1lPSJMaWZlQ3ljbGVFbnRyeSI+CiAgPHhzOnNlcXVlbmNlPgogICA8eHM6ZWxlbWVudCBta        W5PY2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgdHlwZT0ibnMxOklkZW50aWZpY2F0aW9uIiBuY        W1lPSJDcmVhdGluZ0luc3RhbmNlIi8+CiAgIDx4czplbGVtZW50IG1pbk9jY3Vycz0iMCIgb        WF4T2NjdXJzPSIxIiB0eXBlPSJuczE6SWRlbnRpZmljYXRpb24iIG5hbWU9IldyaXRpbmdJb        nN0YW5jZSIvPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0iMSIgd        HlwZT0idWE6RGF0YVZhbHVlIiBuYW1lPSJEYXRhIi8+CiAgIDx4czplbGVtZW50IG1pbk9jY        3Vycz0iMCIgbWF4T2NjdXJzPSIxIiB0eXBlPSJ4czpzdHJpbmciIG5hbWU9IlN1YmplY3QiL        z4KICAgPHhzOmVsZW1lbnQgbWluT2NjdXJzPSIwIiBtYXhPY2N1cnM9IjEiIHR5cGU9InhzO        nN0cmluZyIgbmFtZT0iRXZlbnRDbGFzcyIvPgogICA8eHM6ZWxlbWVudCBtaW5PY2N1cnM9I        jAiIG1heE9jY3Vycz0iMSIgdHlwZT0ieHM6bG9uZyIgbmFtZT0iSWQiLz4KICA8L3hzOnNlc        XVlbmNlPgogPC94czpjb21wbGV4VHlwZT4KIDx4czplbGVtZW50IHR5cGU9InRuczpMaWZlQ        3ljbGVFbnRyeSIgbmFtZT0iTGlmZUN5Y2xlRW50cnkiLz4KIDx4czpjb21wbGV4VHlwZSBuY        W1lPSJMaXN0T2ZMaWZlQ3ljbGVFbnRyeSI+CiAgPHhzOnNlcXVlbmNlPgogICA8eHM6ZWxlb        WVudCBtaW5PY2N1cnM9IjAiIG1heE9jY3Vycz0idW5ib3VuZGVkIiB0eXBlPSJ0bnM6TGlmZ        UN5Y2xlRW50cnkiIG5hbWU9IkxpZmVDeWNsZUVudHJ5IiBuaWxsYWJsZT0idHJ1ZSIvPgogI        DwveHM6c2VxdWVuY2U+CiA8L3hzOmNvbXBsZXhUeXBlPgogPHhzOmVsZW1lbnQgdHlwZT0id        G5zOkxpc3RPZkxpZmVDeWNsZUVudHJ5IiBuYW1lPSJMaXN0T2ZMaWZlQ3ljbGVFbnRyeSIgb        mlsbGFibGU9InRydWUiLz4KPC94czpzY2hlbWE+Cg==");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6003_variant_DataContents, &UA_TYPES[UA_TYPES_BYTESTRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6003);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 72);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_0, 92);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "TypeDictionary");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6003), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 72), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=6003/1:TypeDictionary using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6006), 1:LifeCycleEntry
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "LifeCycleEntry");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6006_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6006_variant_DataContents = UA_STRING_ALLOC("//xs:element[@name='LifeCycleEntry']");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6006_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6006);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 69);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_2, 6003);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "LifeCycleEntry");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6006), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 69), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=6001/1:TypeDictionary using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=6002), NamespaceUri
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6002_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6002_variant_DataContents = UA_STRING_ALLOC("http://acplt.org/lifeCycleEntry/");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6002_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6002);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 68);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_2, 6001);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "NamespaceUri");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6002), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=6003/1:TypeDictionary using i=46/HasProperty
// Node: opcua_node_variable_t(ns=2;i=6004), NamespaceUri
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_String *opcua_node_variable_t_ns_2_i_6004_variant_DataContents =  UA_String_new();
*opcua_node_variable_t_ns_2_i_6004_variant_DataContents = UA_STRING_ALLOC("http://acplt.org/lifeCycleEntry/Types.xsd");
UA_Variant_setScalar( &attr.value, opcua_node_variable_t_ns_2_i_6004_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6004);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 68);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_2, 6003);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 46);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "NamespaceUri");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6004), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 68), true);
} while(0);

do {
// Referencing node found and declared as parent: i=58/BaseObjectType using i=45/HasSubtype
// Node: opcua_node_objectType_t(ns=2;i=1002), 1:LifeCycleArchiveType
UA_ObjectTypeAttributes attr;
UA_ObjectTypeAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "LifeCycleArchiveType");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 1002);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_0, 58);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 45);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "LifeCycleArchiveType");
UA_Server_addObjectTypeNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , attr, NULL, NULL);
} while(0);

do {
// Referencing node found and declared as parent: ns=2;i=1002/1:LifeCycleArchiveType using i=47/HasComponent
// Node: opcua_node_variable_t(ns=2;i=6007), 1:<LifeCycleEntries>
UA_VariableAttributes attr;
UA_VariableAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "<LifeCycleEntries>");
attr.description = UA_LOCALIZEDTEXT("", "");
attr.accessLevel = 3;
attr.valueRank = -1;
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 6007);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 63);
UA_NodeId parentNodeId = UA_NODEID_NUMERIC(nsIdx_2, 1002);
UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(nsIdx_0, 47);
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(nsIdx_2, "<LifeCycleEntries>");
UA_Server_addVariableNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 62), true); //remove HasTypeDefinition refs generated by addVariableNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6007), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 63), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6007), UA_NODEID_NUMERIC(nsIdx_0, 37), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 11510), true);
} while(0);

do {
// Referencing node not found. Adding Node without parent and resolving parent reference (hopefully) later.
// Node: opcua_node_object_t(ns=2;i=5001), Default Binary
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Default Binary");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 5001);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 76);
UA_NodeId parentNodeId = UA_NODEID_NULL;
UA_NodeId parentReferenceNodeId = UA_NODEID_NULL;
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "Default Binary");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 58), true); //remove HasTypeDefinition refs generated by addObjectNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5001), UA_NODEID_NUMERIC(nsIdx_0, 38), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 3002), false);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5001), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 76), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5001), UA_NODEID_NUMERIC(nsIdx_0, 39), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 6005), true);
//  Creating this node has resolved the following open references:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 3002), UA_NODEID_NUMERIC(nsIdx_0, 38), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 5001), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6005), UA_NODEID_NUMERIC(nsIdx_0, 39), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 5001), false);
} while(0);

do {
// Referencing node not found. Adding Node without parent and resolving parent reference (hopefully) later.
// Node: opcua_node_object_t(ns=2;i=5002), Default XML
UA_ObjectAttributes attr;
UA_ObjectAttributes_init(&attr);
attr.displayName = UA_LOCALIZEDTEXT("", "Default XML");
attr.description = UA_LOCALIZEDTEXT("", "");
UA_NodeId nodeId = UA_NODEID_NUMERIC(nsIdx_2, 5002);
UA_NodeId typeDefinition = UA_NODEID_NUMERIC(nsIdx_0, 76);
UA_NodeId parentNodeId = UA_NODEID_NULL;
UA_NodeId parentReferenceNodeId = UA_NODEID_NULL;
UA_QualifiedName nodeName = UA_QUALIFIEDNAME(0, "Default XML");
UA_Server_addObjectNode(server, nodeId, parentNodeId, parentReferenceNodeId, nodeName
       , typeDefinition
       , attr, NULL, NULL);
UA_Server_deleteReference(server, nodeId, UA_NODEID_NUMERIC(0, 40), true, UA_EXPANDEDNODEID_NUMERIC(0, 58), true); //remove HasTypeDefinition refs generated by addObjectNode
// This node has the following references that can be created:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5002), UA_NODEID_NUMERIC(nsIdx_0, 38), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 3002), false);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5002), UA_NODEID_NUMERIC(nsIdx_0, 40), UA_EXPANDEDNODEID_NUMERIC(nsIdx_0, 76), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 5002), UA_NODEID_NUMERIC(nsIdx_0, 39), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 6006), true);
//  Creating this node has resolved the following open references:
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 3002), UA_NODEID_NUMERIC(nsIdx_0, 38), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 5002), true);
UA_Server_addReference(server, UA_NODEID_NUMERIC(nsIdx_2, 6006), UA_NODEID_NUMERIC(nsIdx_0, 39), UA_EXPANDEDNODEID_NUMERIC(nsIdx_2, 5002), false);
} while(0);
return UA_STATUSCODE_GOOD;
}
