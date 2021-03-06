from ert.cwrap import BaseCClass, CWrapper
from ert.enkf import ENKF_LIB, LocalObsdataNode


class LocalObsdata(BaseCClass):

    def __init__(self, name):
        assert isinstance(name, str)

        c_pointer = LocalObsdata.cNamespace().alloc(name)
        super(LocalObsdata, self).__init__(c_pointer)

    def __len__(self):
        """ @rtype: int """
        return LocalObsdata.cNamespace().size(self)


    def __getitem__(self, key):
        """ @rtype: LocalObsdataNode """
        if isinstance(key , int):
            if int < len:
                return LocalObsdata.cNamespace().iget_node(self, key).setParent(self)
            else:
                raise IndexError("Invalid index")
        else:
            if key in self:
                return LocalObsdata.cNamespace().get_node(self, key).setParent(self)
            else:
                raise KeyError("Unknown key:%s" % key)
        
    def __iter__(self):
        cur = 0
        while cur < len(self):
            yield self[cur]
            cur += 1
                    
    def __contains__(self, item):
        """ @rtype: bool """
        if isinstance(item, str):
            return LocalObsdata.cNamespace().has_node(self, item)
        elif isinstance(item, LocalObsdataNode):
            return LocalObsdata.cNamespace().has_node(self, item.getKey())

        return False
    
    def __delitem__(self, key):
        assert isinstance(key, str)
        if key in self:
            LocalObsdata.cNamespace().del_node(self, key)  
        else:
            raise KeyError("Unknown key:%s" % key)                
    
    def addNode(self, node):
        """ @rtype: bool """
        assert isinstance(node, LocalObsdataNode)
        node.convertToCReference(self)
        already_exists_node_for_key = LocalObsdata.cNamespace().add_node(self, node)
        return already_exists_node_for_key
          
    def clear(self):        
        LocalObsdata.cNamespace().clear(self)        
    
    def addObsVector(self , obs_vector):
        self.addNode( obs_vector.createLocalObs() )
    
    def addNodeAndRange(self, key, step_1, step_2):
        """ @rtype: bool """
        assert isinstance(key, str)
        assert isinstance(step_1, int)
        assert isinstance(step_2, int)
        
        node = LocalObsdataNode(key)  
        node.addRange(step_1, step_2)      
        node.convertToCReference(self)
        already_exists_node_for_key = LocalObsdata.cNamespace().add_node(self, node)
        return already_exists_node_for_key

    def getName(self):
        """ @rtype: str """
        return LocalObsdata.cNamespace().name(self)

    def free(self):
        LocalObsdata.cNamespace().free(self)



cwrapper = CWrapper(ENKF_LIB)
cwrapper.registerObjectType("local_obsdata", LocalObsdata)

LocalObsdata.cNamespace().alloc     = cwrapper.prototype("c_void_p local_obsdata_alloc(char*)")
LocalObsdata.cNamespace().free      = cwrapper.prototype("void local_obsdata_free(local_obsdata)")
LocalObsdata.cNamespace().size      = cwrapper.prototype("int local_obsdata_get_size(local_obsdata)")
LocalObsdata.cNamespace().has_node  = cwrapper.prototype("bool local_obsdata_has_node(local_obsdata, char*)")
LocalObsdata.cNamespace().add_node  = cwrapper.prototype("bool local_obsdata_add_node(local_obsdata, local_obsdata_node)")
LocalObsdata.cNamespace().del_node  = cwrapper.prototype("void local_obsdata_del_node(local_obsdata, char*)")
LocalObsdata.cNamespace().clear     = cwrapper.prototype("void local_dataset_clear(local_obsdata)")
LocalObsdata.cNamespace().iget_node = cwrapper.prototype("local_obsdata_node_ref local_obsdata_iget(local_obsdata, int)")
LocalObsdata.cNamespace().get_node  = cwrapper.prototype("local_obsdata_node_ref local_obsdata_get(local_obsdata, char*)")
LocalObsdata.cNamespace().name      = cwrapper.prototype("char* local_obsdata_get_name(local_obsdata)")



