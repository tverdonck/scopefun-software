print_stdout = print

print = function(...)
   local arg = { ... }
   for i,v in ipairs(arg) do
      LuaPrint(v)
   end
end

-- onFrame
function onFrame(data,length,pos,zoom,user)
	return data,length,pos,zoom,user
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig,pos,zoom,user)
    return sample,ch0,ch1,fun,dig,pos,zoom,user
end

-- onDisplay
function onDisplay(data,pos,zoom,user)
  return data,pos,zoom,user
end

-- onConfigure
function onConfigure(hw)
  return hw
end

-- onInit
function onInit(ctx)
  return ctx
end

