<?php
require_once "SCA/SCA.php";

/**
 * @service
 * @binding.atom
 */
class ComponentUpdateSimpleReturnResponse {

	/**
	 * Just indicate that the input got here and matched the input sent by the client.
	 *
	 */
	function update($in)
	{
		return;
	}
}