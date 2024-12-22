/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:59:32 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/22 16:05:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>

class ICharacter
{
    ICharacter(void);
    ICharacter(ICharacter & rhs);
    ICharacter & operator=(ICharacter & rhs);
    virtual~ICharacter(void);

    virtual std::string const & getName() const = 0;
    


    
}

#endif